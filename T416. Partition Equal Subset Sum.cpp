class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2)return false;
        int sum = 0,max_n = 0;
        for(int i : nums){
            sum += i;
            max_n = max(i,max_n);
        }
        if(sum % 2 || max_n > sum / 2)
            return false;
        sum /= 2;
        vector<int>dp(sum + 1,0);
        dp[0] = 1;
        for(int num : nums){
            for(int i = sum;i >= 0; --i){
                if(dp[i] == 1 && i + num <= sum)
                    dp[i + num] = 1;
            }
            if(dp[sum] == 1)return true;
        }
        return false;
    }
};