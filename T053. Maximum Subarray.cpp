class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int>dp = vector<int>(n);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i];
            if(dp[i - 1] >= 0)
                dp[i] += dp[i - 1];
            res = max(dp[i],res);
        }
        return res;
    }
};