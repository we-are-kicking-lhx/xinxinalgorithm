class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.empty() || nums.front()>0 || nums.back()<0) return{};
        // 要加int()
        for(int i=0;i<(int)nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i],j=(int)nums.size()-1,k=i+1;
            while(k<j){
                if(nums[k]+nums[j]==target){
                    res.push_back({nums[i],nums[k],nums[j]});
                    while(k<j && nums[k]==nums[k+1]) k++;
                    while(k<j && nums[j]==nums[j-1]) j--;
                    k++,j--;
                }else if(nums[k]+nums[j]<target) k++;
                else j--;
            }
        }
        return res;
    }
};