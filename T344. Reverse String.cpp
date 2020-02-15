class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0,right = n - 1;
        while(left < right){
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++;
            right--;
        }
    }
};