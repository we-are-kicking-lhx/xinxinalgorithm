class Solution {
public:
    int reverse_pos(vector<int>&nums){
        int n = nums.size();
        int left = 0,right = n - 1;
        if (nums[left] <= nums[right])
            return 0;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] >  nums[mid + 1])
                return mid + 1;
            else if(nums[mid] < nums[left])//这里的边界定义相邻偏好是左偏还是右偏
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)
            return -1;
        int index = reverse_pos(nums);
        int left = 0,right = n - 1;
        if(target > nums[n - 1])
            right = index - 1;
        else
            left = index;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};