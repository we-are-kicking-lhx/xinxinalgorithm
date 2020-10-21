class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0},column[9][9] = {0},box[9][9] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if(row[i][num])
                    return false;
                if(column[j][num])
                    return false;
                if (box[(i/3)*3+j/3][num])
                    return false;
                row[i][num] = 1;
                column[j][num] = 1;
                box[(i/3)*3+j/3][num] = 1;
            }
        }
        return true;
    }
};
