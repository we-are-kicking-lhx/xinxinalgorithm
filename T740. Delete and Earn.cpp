class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int a[10001] = {0};
        int max_num = 0;
        for(auto i :nums){
            a[i]++;
            max_num = max_num > i ? max_num : i;
        }
        int dp[10001] = {0};
        dp[1] = a[1] * 1;
        for(int i = 2;i <= max_num;i++){
            dp[i] = max(dp[i-2]+ a[i] * i,dp[i-1]);
        }
        return dp[max_num];
    }
};