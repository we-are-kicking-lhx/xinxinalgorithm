class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)return false;
        int index = 0;
        for (int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]){
                index = i;
                break;
            }
        }
        int s,e;
        if(target > nums[n - 1]){
            s = 0;
            e = index - 1;
        }
        else{
            s = index;
            e = n - 1;
        }
        while (s <= e) {
            int mid = (s+e)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};