class Solution {
public:
    int minimumOperations(string leaves) {
        int n = leaves.length();
        vector<vector<int>>dp(3,vector<int>(n,0));
        dp[0][0] = leaves[0] == 'y';
        dp[1][0] = 100000;
        dp[2][0] = 100000;
        for(int i = 1;i < n; ++i){
            dp[0][i] = dp[0][i-1] + (leaves[i] == 'y');
            dp[1][i] = min(dp[0][i-1],dp[1][i-1]) + (leaves[i] == 'r');
            dp[2][i] = min(dp[1][i-1],dp[2][i-1]) + (leaves[i] == 'y');
        }
        return dp[2][n-1];
    }
};