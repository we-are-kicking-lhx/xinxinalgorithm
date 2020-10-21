struct Trie{
    bool isEnd;
    Trie *links[26];
    Trie(){
        isEnd = false;
        memset(links, 0, sizeof(links));
    }
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
bool cmp(string s1,string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() > s2.length();
}
class Solution {
public:
    Trie *root = new Trie();
    bool dfs(string word,Trie *trie,int idx,int cut){
//        cout << word[idx] << "::";
        if(trie->links[word[idx] - 'a'] == NULL)
            return false;
        if(idx == word.length() - 1)return cut==1&&trie->links[word[idx] - 'a']->isEnd;
        if(trie->links[word[idx] - 'a']->isEnd)
            return dfs(word,root,idx+1,1) || dfs(word,trie->links[word[idx] - 'a'],idx+1,cut);
        return dfs(word,trie->links[word[idx] - 'a'],idx+1,cut);
    }
    string longestWord(vector<string>& words) {
        for(auto word : words){
            root->insert(word);
        }
        sort(words.begin(),words.end(),cmp);
        for(auto word : words){
            if(word!=""&&dfs(word,root,0,0))
                return word;
        }
        return "";
    }
};