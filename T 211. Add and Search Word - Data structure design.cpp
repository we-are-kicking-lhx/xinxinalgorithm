class WordDictionary {
private:
    bool isEnd;
    WordDictionary *next[26];
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary *node = this;
        for(char c : word){
            if(node->next[c-'a']==NULL){
                node->next[c-'a'] = new WordDictionary();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return search_word(word,this);
    }
    bool search_word(string word,WordDictionary *node){
        if(word.length() == 1){
            if(word == "."){
                for(auto it:node->next){
                    if(it!=NULL && it->isEnd)return true;
                }
                return false;
            }
            else return node->next[word[0] - 'a'] && node->next[word[0] - 'a']->isEnd;
        }
        if(word[0] == '.'){
            for(auto it : node->next){
                if(it!=NULL){
                    if(search_word(word.substr(1, word.size()-1),it)){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            if(!node->next[word[0] - 'a'])
                return false;
            return search_word(word.substr(1, word.size()-1),node->next[word[0] - 'a']);
        }
    }
};