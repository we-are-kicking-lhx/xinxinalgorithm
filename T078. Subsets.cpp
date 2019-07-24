class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if(((1 << j) & i )!= 0){
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
//1.位运算的优先级要低于逻辑运算
//1.移位运算符是数字移动