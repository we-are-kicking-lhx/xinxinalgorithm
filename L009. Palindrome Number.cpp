class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string str=to_string(x);
        return isPalindromeStr(str);
    }
    bool isPalindromeStr(string str){
        if(str.length()==0 || str.length()==1) return true;
        if(str[0]==str[str.length()-1]) return isPalindromeStr(str.substr(1,str.length()-2));
        else return false;
    }
};