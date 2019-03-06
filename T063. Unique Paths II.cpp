class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        long long dp[105][105] = {0,1};
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 1; i <= m; ++i)
        {
        	for (int j = 1; j <= n; ++j)
        	{
        		if(obstacleGrid[i-1][j-1]==1)
        			dp[i][j] = 0;
        		else 
        			dp[i][j] = dp[i][j-1]+dp[i-1][j];
        	}
        }
        return dp[m][n];
    }
};

//测试样例开int会溢出
//实际上如果样例里存在上限值，连long long都不够存 ;)