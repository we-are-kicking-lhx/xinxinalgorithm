class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos1 = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
        int pos2 = upper_bound(nums.begin(), nums.end(),target) - nums.begin();
        if (pos1 == pos2)
            return vector<int>{-1,-1};
        else
            return vector<int>{pos1,pos2-1};
    }
};
//注意题目是要求最后一个出现的位置，而upper_bound是最后一个插入位置，肯定会插入在最后一个出现之后，所以要减1