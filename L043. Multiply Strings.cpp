class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int len1 = num1.length(), len2 = num2.length();
        vector<int> ans(len1 + len2);
        string str = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                ans[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] > 9) {
                ans[i + 1] += ans[i] / 10;
                ans[i] = ans[i] % 10;
                
            }
            str = to_string(ans[i]) + str;
        }
        int pos = 0;
        while (str[pos++] == '0');
        return str.substr(pos-1, str.length() - pos+1);
        // 报错：control reaches end of non-void function [-Werror=return-type]
        // for (int i = 0; i < str.length(); i++) {
        //     if (str[i] != '0') return str.substr(i, str.length() - i);
        // }
    }
};