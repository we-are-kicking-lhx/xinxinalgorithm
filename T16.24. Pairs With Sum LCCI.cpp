class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int,int>hashmap;
        vector<vector<int>> ans;
        for(auto i : nums){
            if(hashmap[target - i] > 0){
                hashmap[target - i]--;
                vector<int>v = {target-i,i};
                ans.emplace_back(v);
            }
            else{
                hashmap[i]++;
            }
        }
        return ans;
    }
};