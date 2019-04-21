class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        if (last == -1) return true;
        for (int i = last - 1; i >= 0; i--) {
            if(nums[i] >= last - i){
                last = i;
            }
        }
        if(last)return false;
        return true;
    }
};