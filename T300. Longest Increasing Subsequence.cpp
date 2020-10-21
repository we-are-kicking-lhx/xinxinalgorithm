//n^2
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp = vector<int>(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i],dp[j]+1);
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};

//nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(!n)return 0;
        vector<int>ans = vector<int>(n + 1);
        ans[1] = nums[0];
        int res = 1;
        for (int i = 1; i < n; i++) {
            if(nums[i] > ans[res])
                ans[++res] = nums[i];
            else{
                int pos = lower_bound(ans.begin()+1, ans.begin()+res+1, nums[i]) - ans.begin();
                ans[pos] = nums[i];
            }
        }
        return res;
    }
};
