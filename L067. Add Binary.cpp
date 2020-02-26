class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = 0, j = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        while (i < a.length() && j < b.length()) {
            int temp = a[i] - '0' + b[i] - '0' + carry;
            ans = to_string(temp % 2) + ans;
            carry = temp / 2;
            i++; j++;
        }
        while (i < a.length()) {
            int temp = a[i] - '0' + carry;
            ans = to_string(temp % 2) + ans;
            carry = temp / 2;
            i++;;
        }
        while (j < b.length()) {
            int temp = b[j] - '0' + carry;
            ans = to_string(temp % 2) + ans;
            carry = temp / 2;
            j++;;
        }
        if (carry == 1) return "1" + ans;
        else return ans;
    }
};
// 好像可以直接用库的。。。