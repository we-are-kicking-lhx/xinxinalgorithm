class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x/2 + 1;
        long long mid;
        while (left < right) {
            mid = (left + right + 1)/2;
            if(mid * mid > x)
                right = mid - 1;
            else
                left = mid;
        }
        return left;
    }
};