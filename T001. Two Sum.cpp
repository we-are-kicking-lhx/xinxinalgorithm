class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i = 0;i < nums.size(); i++){
            int m = target - nums[i];
            if(hashmap.count(m) > 0){
                return {hashmap[m],i};
            }
            hashmap[nums[i]] = i;
        }
        return {};
    }
};