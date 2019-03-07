class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())return 0; //nums为空的情况
        vector<int>ans = vector<int>(nums.size()+1,0);
        ans[1] = nums[0];
        int cur = 1;//当前最长子序列长度
        for (int i = 1; i < nums.size(); ++i)
        {
        	if(nums[i] > ans[cur]) 
        		ans[++cur] = nums[i];
        	else{
        		int pos = lower_bound(ans.begin()+1,ans.begin()+cur+1,nums[i]) - ans.begin();
        		ans[pos] = nums[i];
        	}
        }
        return cur;
    }
};
//dp[i] 以第i个字符结尾 最长的子序列个数
//ans[i] 最长子序列长度为i 的最小结尾数