class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>ans;
        for(int i = 0;i < n;i++){
            ans.emplace_back(nums[i]);
            for(int j = i + 1;j < n;j++){
                ans.emplace_back(ans.back()+nums[j]);
            }
        }
        sort(ans.begin(),ans.end());
        int res = 0;
        for(int i = left -1 ;i < right;i++){
            res += ans[i];
        }
        res = res % (int)(pow(10,9)+7);
        return res;
    }
};