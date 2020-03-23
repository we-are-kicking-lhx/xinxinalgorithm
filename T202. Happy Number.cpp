class Solution {
public:
    int value(int n){
        int sum = 0;
        while(n != 0){
            int bit = n % 10;
            sum += (bit * bit);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast != 1){
            slow = value(slow);
            fast = value(fast);
            fast = value(fast);
            if(slow == fast && slow != 1)
                return false;
        }
        return true;

    }
};