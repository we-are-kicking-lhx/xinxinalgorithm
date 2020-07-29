class Solution {
public:
    struct Trie{
        Trie* next[26];
        bool isEnd;
        
        void insert(string word){
            Trie* node = this;
            for(char c : word){
                if(!node->next[c-'a'])
                    node->next[c-'a'] = new Trie();
                node = node->next[c-'a'];
            }
            node->isEnd = true;
        }
    };
    unordered_set<string>ans;
    void backtrack(Trie *t,vector<vector<char>>&board,int x,int y,string word){
        Trie *node = t->next[board[x][y]-'a'];
        if(node){
            word = word + board[x][y];
            if(node->isEnd)
                ans.insert(word);
            char temp = board[x][y];
            board[x][y] = '#';
            int offset[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
            for(int i = 0;i < 4;i++){
                int x0 =x+ offset[i][0];
                int y0 =y+offset[i][1];
                if(x0 >= 0 && x0 < board.size() && y0 >=0 && y0 < board[0].size() && board[x0][y0] != '#')
                    backtrack(node, board, x0, y0, word);
            }
            board[x][y] = temp;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        Trie *t = new Trie();
        for(string i : words)
            t->insert(i);
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                backtrack(t, board, i, j, "");
            }
        }
        return vector<string>(ans.begin(),ans.end());
    }
};