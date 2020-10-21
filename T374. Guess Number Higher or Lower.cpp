class Solution {
public:
    int guessNumber(int n) {
        int left = 1,right = n;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            int ans = guess(mid);
            if(!ans)
                return mid;
            else if(ans == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }
};