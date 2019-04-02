class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[11];
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = 91;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - (i - 1));
        }
        return dp[n];
    }
};