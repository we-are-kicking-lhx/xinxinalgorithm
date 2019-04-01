class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans,one = 0;
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        ans = dp[0][0] = matrix[0][0] - '0';
        for (int i = 1; i < n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            one += dp[i][0];
        }
        for (int i = 1;i < m;i++){
            dp[0][i] = matrix[0][i] - '0';
            one += dp[0][i];
        }
        if(one)ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1])) + 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};