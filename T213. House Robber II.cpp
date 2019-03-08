class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size()==0) return 0;
    	if(nums.size()==1) return nums[0];
    	vector<int> dp = vector<int>(nums.size(),0);
        dp[0] = nums[0];
    	dp[1] = max(dp[0],nums[1]);
    	for (int i = 2; i < nums.size()-1; ++i)
    	{
    		dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
    	}
    	int rob1 = dp[nums.size()-2];
        
        dp[1] = nums[1];
        if(nums.size()>2)
            dp[2] = max(dp[1],nums[2]);
    	for (int i = 3; i < nums.size(); ++i)
    	{
            
    		dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
    	}
    	int rob2 = dp[nums.size()-1];
        return max(rob1,rob2);
    }
};
//做两次(0,n-2)和(1,n-1)