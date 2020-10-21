class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1,vector<int>(m+1,INT_MAX));
        long long sum[1001] = {};
        for(int i = 1;i <= n; i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for(int i = 2;i <= n;i++){
            dp[i][1] = sum[i];
        }
        for(int i = 1;i <= m;i++){
            dp[1][i] = nums[0];
        }
        for(int i = 2;i <= n;i++){
            for(int j = 2;j <= m;j++){
                for(int k = 1;k < i;k++){
                    dp[i][j] = min(dp[i][j],max(dp[k][j-1],(int)(sum[i] - sum[k])));
                }
            }
        }
        return dp[n][m];
    }
};