class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp = vector<int>(n+1);
        dp[1] = 1;
        if(dp.size() > 2)dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};