class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int sub[9][9] = {0};
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j]!='.'){
                    int num = int(board[i][j]-'1');
                    if(rows[i][num])return false;
                    rows[i][num] = 1;
                    if(cols[j][num])return false;
                    cols[j][num] = 1;
                    if(sub[(i/3)*3+j/3][num])return false;
                    sub[(i/3)*3+j/3][num] = 1;
                }
            }
        }
        return true;
    }
};