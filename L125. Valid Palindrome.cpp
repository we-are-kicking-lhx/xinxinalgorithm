class Solution {
public:
    bool isPalindrome(string s)
    {
        bool flag = true;
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!func(s[i]))
                i++;
            if (!func(s[j]))
                j--;
            if (func(s[i]) && func(s[j])) {
                if (tolower(s[i]) == tolower(s[j])) {
                    i++;
                    j--;
                } else {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    bool func(char ch)
    {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
            return true;
        else
            return false;
    }
};
// C 库函数 void isalnum(int c) 检查所传的字符是否是字母和数字。
