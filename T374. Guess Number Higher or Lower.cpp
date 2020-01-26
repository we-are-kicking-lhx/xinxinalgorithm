// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long left = 0;
        long long right = n;
        long long mid = 1;
        while(left < right){
            mid = (left + right + 1) >> 1;
            if(guess(mid)==1)
                left = mid;
            else if(guess(mid)==-1)
                right = mid -1;
            else
                return mid;
        }
        return left;
    }
};