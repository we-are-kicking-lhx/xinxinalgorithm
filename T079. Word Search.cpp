class Solution {
public:
    bool search(vector<vector<char>>&board,string word,int x,int y){
        if(word.length() == 1)
            return board[x][y] == word[0];
        if(board[x][y] != word[0])
            return false;
        char temp = board[x][y];
        board[x][y] = '#';
        int offset[][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i = 0;i < 4;i++){
            int x0 = x + offset[i][0];
            int y0 = y + offset[i][1];
            if(x0 >= 0 && x0 < board.size() && y0 >= 0 && y0 < board[0].size() && board[x0][y0] != '#'){
                if(search(board,word.substr(1, word.size()-1),x0,y0))return true;
            }
        }
        board[x][y] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if(search(board,word,i,j))
                    return true;
            }
        }
        return false;
    }
};