class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0,right = num / 2 + 1;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long prod = mid * mid;
            if(prod == num)
                return true;
            if(prod < num)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
