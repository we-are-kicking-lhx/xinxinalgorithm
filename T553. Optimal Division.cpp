class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int len = nums.size();       
        if(len == 1) return to_string(nums[0]);
        if(len == 2) return to_string(nums[0]) + "/" + to_string(nums[1]);
        
        string res = to_string(nums[0]) + "/(";
        for(int i = 1; i < len - 1; i++){
            res += to_string(nums[i]);
            res += "/";
        }
        res += to_string(nums[len-1]);
        res += ")";
        
        return res;
    }
};
//分子最大，分母最小