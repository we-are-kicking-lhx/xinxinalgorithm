class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = n - 1;
        if(nums[left] <= nums[right])
            return nums[0];
        while (left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[left] > nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
                
        }
        return nums[0];
    }
};