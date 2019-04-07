class Solution {
public:
    int mess(int i , int a , int b){
        if (i)
            return a < b;
        else
            return a > b;
    }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int last = nums[0],len1 = 1,len2 = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(last == nums[i])
                continue;
            if (mess(len1%2, last, nums[i]))
                len1++;
            if (!mess(len2%2, last, nums[i])) {
                len2++;
            }
            last = nums[i];
        }
        return max(len2,len1);
    }
};