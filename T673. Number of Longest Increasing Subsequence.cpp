class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int dp[2005] = {0};
        int dp_num[2005] = {0};//记录以i结尾的LIS个数
        int mx = 0, res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            dp_num[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        dp_num[i] = dp_num[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                        dp_num[i] += dp_num[j];
                    
                }
            }
            if(dp[i] > mx){
                res = dp_num[i];
                mx = dp[i];
            }
            else if(dp[i] == mx)
                res += dp_num[i] ;
        }
        
        return res;
    }
};