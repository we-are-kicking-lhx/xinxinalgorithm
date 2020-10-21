class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1 = 1,p2 = 1;
        int n1 = s.size(),n2 = t.size();
        while (p2 <= n2 && p1 <= n1) {
            if(s[p1 - 1] == t[p2 - 1])
                p1++;
            p2++;
        }
        if(p1 > n1)
            return true;
        else
            return false;
    }
};