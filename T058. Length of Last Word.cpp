class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int cnt = 0,last = len - 1;
        while (last >= 0) {
            if(s[last] != ' ')
                break;
            last--;
        }
        
        while (last >= 0) {
            if (s[last] == ' ')
                break;
            cnt++;
            last--;
        }
        
        return cnt;
    }
};