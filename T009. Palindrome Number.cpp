class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        if(x / 10 == 0)return true;
        if(x % 10 == 0) return false;
        int r = 0;
        while (x > r) {
            r = 10 * r + x % 10;
            x /= 10;
        }
        return x == r || x == r / 10;
    }
};
//反转一半，不用担心溢出