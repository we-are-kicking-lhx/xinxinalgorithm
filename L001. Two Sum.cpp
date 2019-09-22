class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>a;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(a.find(temp)!=a.end()) return vector<int>{i,a[temp]};
            a[nums[i]]=i;
        }
        return {};
    }
};