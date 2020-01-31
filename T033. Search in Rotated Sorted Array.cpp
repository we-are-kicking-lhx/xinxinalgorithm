class Solution {
public:
    int get_rotate_index(vector<int>nums){
        int n = nums.size();
        int left = 0,right = n - 1;
        if (nums[left] <= nums[right])
            return 0;
        while (left <= right) {
            int mid = (right + left)/2;
            if (nums[mid] > nums[mid + 1])
                return mid + 1;
            else{
                if (nums[mid] < nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)return -1;
        int index = get_rotate_index(nums);
        int left = 0,right = n - 1;
        if(target <= nums[n - 1])
            left = index;
        else
            right = index - 1;
        while (left <= right) {
            int mid = (right + left) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
//两个二分 第一个二分查找折点 第二个二分查找插入数据位置 边界值判断极其恶心
