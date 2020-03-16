class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0) return false;
        int m=0,n=matrix[0].size()-1;
        while(m<(int)matrix.size() && n>=0){
            if(matrix[m][n]>target) n--;
            else if(matrix[m][n]<target) m++;
            else 
                return true;
        }
        return false;
    }
};