class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        if (end < 0) {
            return 0;
        }
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return end - start;
    }
};
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         if(s.length()==0) return 0;
//         reverse(s.begin(), s.end());
//         size_t start = s.find(' ');
//         if(start==string::npos) return s.length();
//         if (s[0] != ' ') return start;
//         while (s[start] == ' ') start++;
//         if (start == s.length()) return 0;
//         size_t finish = s.find(' ', start);
//         if(finish==string::npos) return s.length()-start;
//         else return finish - start;
//     }
// };