class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>num1(nums1.begin(),nums1.end());
        set<int>num2(nums2.begin(),nums2.end());
        vector<int>res;
        for(auto i : num2){
            if(binary_search(num1.begin(), num1.end(),i))
                res.push_back(i);
        }
        return res;
    }
};