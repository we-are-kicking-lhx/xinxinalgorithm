class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())return 0;
        int ans;
        vector<int>dp = vector<int>(nums.size(),0);
        ans = dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(dp[i - 1] > 0)
                dp[i] = dp[i - 1] + nums[i];
            else
                dp[i] = nums[i];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};