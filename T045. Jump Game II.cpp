//贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return 0;
        int next = nums[0],now = 0;
        int step = 0;
        for (int i = 0; i < len; i++) {
            next = max(next , i + nums[i]);
            if (next >= len - 1){
                return ++step;
            }
            if(i == now){
                now = next;
                step++;
            }
        }
        return step;
    }
};
