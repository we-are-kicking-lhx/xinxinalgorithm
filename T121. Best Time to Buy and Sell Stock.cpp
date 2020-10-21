class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n)return 0;
        vector<int>dp = vector<int>(n);
        dp[0] = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[i - 1],prices[i]);
            res = max(res,prices[i] - dp[i]);
        }
        return res;
    }
};