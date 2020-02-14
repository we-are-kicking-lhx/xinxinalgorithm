class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if(!n)return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int left = 0,right = n - 1;
        while(left < right){
            if(!isdigit(s[left])&&!isalpha(s[left])){
                left++;
                continue;
            }
            if(!isdigit(s[right])&&!isalpha(s[right])){
                right--;
                continue;
            }
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};