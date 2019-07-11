const int int_max = 2147483647;
const int int_min = -2147483648;
class Solution {
public:
    int reverse(int x) {
        if(x == 0)
            return 0;
        int res = 0;
        while (x!=0) {
            int pop = x % 10;
            x /= 10;
            if(res > int_max/10) return 0;
            if(res < int_min/10) return 0;
            res = 10 * res + pop;
        }
        return res;
    }
};