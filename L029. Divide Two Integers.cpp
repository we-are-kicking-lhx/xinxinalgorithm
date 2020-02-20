class Solution {
public:
    int divide(int dividend, int divisor) {
        long a = dividend, b = divisor;
        long re = 0;
        if (abs(b) == 1) {
            re = 1 == b ? a : -a;
            return min(1.0 * pow(2, 31) - 1, 1.0 * max(-1.0 * pow(2, 31), 1.0 * re));
        }
        int flag = -1;
        if (a > 0 && b > 0 || a < 0 && b < 0) flag = 1;
        long ans = 0;
        a = abs(a); b = abs(b);
        while (a >= b) {
            ans += func(a, b);
            cout<<a<<" "<<ans<<endl;
        }
        return min(1.0 * pow(2, 31) - 1, 1.0 * max(-1.0 * pow(2, 31), 1.0 * ans * flag));
    }
    long func(long &a, long b) {
        long ans = 0;
        int time = 1;
        while (a >= b) {
            a = a - b;
            ans += time;
            time += time;
            b += b;
        }
        return ans;
    }
};
