class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int cur = 0;
        for (int i = 1; i < n; i++) {
            if (nums[cur] != nums[i])
                nums[++cur] = nums[i];
        }
        nums.resize(++cur);
        return cur;
    }
};