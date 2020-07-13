nclass Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++){
            while(i != nums[i]){
                if(nums[nums[i]] == nums[i])
                    return nums[i];
                swap(nums[nums[i]],nums[i]);
            }
        }
        return 0;
    }
};