class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums[0] >= s) return 1;
        int left = 0, right = 0,sum = nums[0],len = 32467;
        //right move
        while (++right < nums.size()) {
            sum += nums[right];
            if (sum >=s) {
                //left move
                int sum0 = sum;
                while (left <= right) {
                    sum0 -= nums[left];
                    left++;
                    if (sum0 < s) {
                        left--;
                        break;
                    }
                    sum = sum0;
                }
                len = min(len, right - left + 1);
            }
        }
        len = len == 32467 ? 0 : len;
        return len;
    }
};