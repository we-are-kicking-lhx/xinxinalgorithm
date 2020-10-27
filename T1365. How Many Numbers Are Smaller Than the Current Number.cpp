class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int a[102] = {0},n = nums.size(),maxn=0;
        for(int i = 0;i < n; ++i){
            maxn = max(maxn,nums[i]);
            a[nums[i]]++;
        }
        for(int i = 1;i <= maxn; ++i){
            a[i] = a[i-1] + a[i];
        }
        vector<int>ans;
        for(auto i : nums){
            ans.emplace_back(i == 0 ? 0 : a[i-1]);
        }
        return ans;
    }
};