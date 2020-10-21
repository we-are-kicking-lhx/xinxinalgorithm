class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>hashmap;
        vector<int>res;
        for(auto i : nums1)
            hashmap[i] = 1;
        for(auto j : nums2){
            if(hashmap[j] == 1){
                hashmap[j] = 0;
                res.push_back(j);
            }
        }
        return res;
            
    }
};