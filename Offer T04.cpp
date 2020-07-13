class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n)return false;
        int m = matrix[0].size();
        for(int row = 0,col = m - 1;row >= 0 && row < n && col >= 0 &&col < m;){
            if(target == matrix[row][col]){
                return true;
            }
            else if(target > matrix[row][col]){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};