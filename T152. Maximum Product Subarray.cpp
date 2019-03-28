class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max = vector<int>(nums.size(),0);
        vector<int> dp_min = vector<int>(nums.size(),0);
        dp_max[0] = dp_max[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp_max = dp_max[i - 1] * nums[i];
            int temp_min = dp_min[i - 1] * nums[i];
            dp_max[i] = max(max(temp_max,temp_min),nums[i]);
            dp_min[i] = min(min(temp_max,temp_min),nums[i]);
            res = max(dp_max[i],res);
        }
        return res; 
    }
};