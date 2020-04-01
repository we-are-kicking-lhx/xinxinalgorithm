class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {},col[9][9] = {},sqr[9][9] = {};
        for(int i = 0;i < 9; ++i){
            for(int j = 0;j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if(row[i][num] > 0)
                    return false;
                if(col[j][num] > 0)
                    return false;
                if(sqr[i / 3 * 3 + j / 3][num] > 0)
                    return false;
                row[i][num] = 1;
                col[j][num] = 1;
                sqr[i / 3 * 3 + j / 3][num] = 1;
            }
        }
        return true;
    }
};