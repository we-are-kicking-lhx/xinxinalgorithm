class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 1;
        long long right = num/2 + 1;
        long long mid;
        while (left <= right) {
            mid = (left + right)/2;
            if (mid * mid == num)
                return true;
            if (mid * mid > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};