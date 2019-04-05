class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int>dp1 = vector<int>(len);
        vector<int>dp2 = vector<int>(len);
        dp1[0] = s[0] == '0' ? 0 : 1;
        dp2[0] = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0')
                dp1[i] = 0;
            else
                dp1[i] = dp1[i - 1] + dp2[i - 1];
            int dnum = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(dnum > 0 && dnum <= 26)
                dp2[i] = dp1[i - 1];
            else
                dp2[i] = 0;
        }
        return dp1[len - 1] + dp2[len - 1];
    }
};