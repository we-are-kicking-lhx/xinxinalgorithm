class Solution {
public:
    int numSquares(int n) {
        vector<int>dp = vector<int>(n+1,0);
        for (int i = 1 ; i <= n; i++) {
            dp[i] = i;
        }
        dp[0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; i >= j*j ; j++) {
                dp[i] = min(dp[i],dp[i - j*j] + 1);
                
            }
        }
        return dp[n];
    }
};