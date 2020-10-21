class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>hashmap;
        vector<int>res;
        for(auto i : nums1)
            hashmap[i]++;
        for(auto j : nums2){
            if(hashmap[j] > 0){
                res.push_back(j);
                hashmap[j]--;
            }
        }
        return res;
    }
};