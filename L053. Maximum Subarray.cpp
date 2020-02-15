// 二分
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return func(nums, 0, nums.size() - 1);
	}
	int func(vector<int>& nums, int start, int end) {
		if (start > end) return INT_MIN;
		int mid = (start + end) / 2;
		int pre_sum = 0, pos_sum = 0;
		int temp = 0;
		for (int i = mid - 1; i >= start; i--) {
			temp += nums[i];
			pre_sum = max(pre_sum, temp);
		}
		temp = pos_sum;
		for (int i = mid + 1; i <= end; i++) {
			temp += nums[i];
			pos_sum = max(temp, pos_sum);
		}
		return max(max(func(nums, start, mid - 1), pre_sum + pos_sum+nums[mid]), func(nums, mid+1, end));
	}
};
// dp

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum=nums[0];
//         vector<int>dp(nums.size());
//         dp[0]=nums[0];
//         for(int i=1;i<nums.size();i++){
//             dp[i]=max(dp[i-1]+nums[i],nums[i]);
//             maxSum=max(maxSum,dp[i]);
//         }
//         return maxSum;
//     }
// };