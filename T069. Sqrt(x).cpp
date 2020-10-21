class Solution {
public:
    int mySqrt(int x) {
        int left = 0,right = x / 2 + 1;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            if(mid * mid == x)
                return mid;
            else if(mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};