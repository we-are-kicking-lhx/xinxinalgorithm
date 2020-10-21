class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        long long dp[105][105] ;
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m ; i++)
            dp[0][i] = (1-obstacleGrid[0][i])*(1-obstacleGrid[0][i-1]) * dp[0][i-1];
        for (int i = 1; i < n; i++)
            dp[i][0] = (1-obstacleGrid[i][0])*(1-obstacleGrid[i-1][0]) * dp[i - 1][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = (1-obstacleGrid[i][j])*((1-obstacleGrid[i][j-1]) * dp[i][j-1] + (1-obstacleGrid[i-1][j]) * dp[i - 1][j]);
            }
        }
        return dp[n-1][m-1];
        
    }
};