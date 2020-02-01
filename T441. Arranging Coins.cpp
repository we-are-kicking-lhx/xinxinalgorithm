class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 1;
        long long right = n;
        while (left <= right) {
            long long mid = (left + right)/2;
            if((1 + mid) * mid / 2 == n)
                return mid;
            if((1 + mid) * mid / 2 > n)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return right;
    }
};