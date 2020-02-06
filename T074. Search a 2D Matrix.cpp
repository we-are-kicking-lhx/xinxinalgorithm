class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m)return false;
        int n = matrix[0].size();
        if(!n)return false;
        int left = 0,right = n * m - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};