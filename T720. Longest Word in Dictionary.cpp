class Solution {
public:
    int max_cnt = 0;
    string max_word = "";
    struct Trie{
        Trie *next[26];
        bool isEnd = false;
        void insert(string word){
            Trie *node = this;
            for(char c : word){
                if(!node->next[c - 'a'])
                    node->next[c-'a'] = new Trie();
                node = node->next[c-'a'];
            }
            node->isEnd = true;
        }
    };
    void dfs(Trie *node,string word,int len){
        for(int i =0;i < 26;i++){
            Trie *it = node->next[i];
            if(it && it->isEnd){
                if(len+1>max_cnt){
                    max_cnt = len+1;
                    max_word = word + char('a'+i);
                }
                dfs(it,word + char('a'+i),len+1);
            }
        }
    }
    string longestWord(vector<string>& words) {
        Trie * trie = new Trie();
        for(string w : words){
            trie->insert(w);
        }
        dfs(trie,"",0);
        return max_word;
    }
};