struct Trie{
    Trie *links[26];
    bool isEnd = false;

    void insert(string word){
        Trie *node = this;
        for(char c : word){
            if(node->links[c - 'a'] == NULL)
                node->links[c - 'a'] = new Trie();
            node = node->links[c - 'a'];
        }
        node->isEnd = true;
    }
};
class Solution {
public:
    Trie *root = new Trie(); 
    vector<int>failure;
    vector<string>ans;
    int dfs(string &s,Trie *trie,int pos,string sn){
        if(!trie->links[s[pos] - 'a'])
            return 0;
        trie = trie->links[s[pos] - 'a'];
        sn += s[pos];
        if(pos == s.length()-1){
            if(trie->isEnd){
                ans.emplace_back(sn);
                return 1;
            }
            return 0;
        }
        int cnt = 0;
        cnt += dfs(s,trie,pos+1,sn);
        if(trie->isEnd && failure[pos+1]==0){
            if(dfs(s,root,pos+1,sn + " "))
                cnt++;
            else
                failure[pos+1] = 1;
        }
        if(cnt)return 1;
        return 0;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        failure = vector<int>(s.length(),0);
        for(string word : wordDict)
            root->insert(word);
        dfs(s,root,0,"");
        return ans;
    }
};