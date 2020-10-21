class Solution {
public:
    int count_pairs(vector<int>& nums,int mid){
        int n = nums.size();
        int left = 0,right = 1;
        int cnt = 0;
        while(left < n - 1){
            if(nums[right] - nums[left] <= mid){
                if(right == n - 1){
                    int m = right - left;
                    cnt += m * (1 + m) / 2;
                    break;
                }
                right++;
            }
            else
                cnt += (right - 1) - left++;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0,right = nums.back() - nums.front();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(count_pairs(nums,mid) < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};