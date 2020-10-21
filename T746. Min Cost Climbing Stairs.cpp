class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(!n) return 0;
        int dp[1005];
        dp[0] = cost[0];
        if(n < 2)return cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        for(int i = 2;i <= n; i++)
            dp[i] = min(dp[i - 1],dp[i - 2]) + cost[i];
        return dp[n];
    }
};