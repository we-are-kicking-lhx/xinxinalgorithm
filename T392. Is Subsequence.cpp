class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p = 0;
        int n = s.length();
        if(!n) return true;
        for (auto c : t) {
            if(c == s[p]){
                p++;
                if(p == n)
                    return true;
            }
        }
        return false;
    }
};