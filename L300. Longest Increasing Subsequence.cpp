// dp[i],以第i个元素结尾的最长子序列长度
// 或者对nums排个序，用LCS方法算
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
			for (int j = 0; j < i; j++)
				if (nums[i] > nums[j])  dp[i] = max(dp[i], dp[j] + 1);
		return *max_element(dp.begin(), dp.end());
	}
};