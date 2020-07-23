class Trie {
private:
    bool isEnd;
    Trie* links[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(links, 0, sizeof(links));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char c : word){
            if(node->links[c-'a'] == NULL){
                node->links[c -'a'] = new Trie();
            }
            node = node->links[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(char c : word){
            if(node->links[c - 'a'] == NULL)
                return false;
            node = node->links[c - 'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char c : prefix){
            if(node->links[c - 'a'] == NULL)
                return false;
            node = node->links[c - 'a'];
        }
        return true;
    }
};