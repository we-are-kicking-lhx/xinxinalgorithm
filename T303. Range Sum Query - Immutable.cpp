class NumArray {
public:
    vector<int>dp;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        dp = vector<int>(n+1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            dp[i] = dp[i - 1] + nums[i - 1];
    }
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
};