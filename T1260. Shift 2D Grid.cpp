class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k %= n * m;
        vector<vector<int>> ans = vector(n,vector<int>(m));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                int order = i * m + j + k;
                ans[(order/m)%n][order % m] = grid[i][j];
            }
        }
        return ans;
    }
};
