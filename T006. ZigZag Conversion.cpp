class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(n < 2 || numRows < 2) return s;
        int col = n / (2 * numRows - 2) + 2;
        string res = "";
        for (int i = 0; i < numRows ; i++) {
            for (int j = 0; j < col; j++) {
                int s_col = j * (2 * numRows - 2);
                if(s_col - i < n && s_col - i >= 0){
                    if (i != 0 && i != numRows - 1)
                        res += s[s_col - i];
                }
                if (s_col + i < n && s_col + i >= 0)
                    res += s[s_col + i];
            }
        }
        return res;
    }
};