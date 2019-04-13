class Solution {
public:
    int argmin(string num,int s,int e){
        int min = num[s], arg = s;
        for (int i = s + 1; i <= e; i++) {
            if (num[i] < min) {
                min = num[i];
                arg = i;
            }
        }
        return arg;
    }
    string removeKdigits(string num, int k) {
        string ans = "";
        int len = num.length() - k;
        if (len == 0) return "0";
        int last = 0;
        for (int i = 0; i < len; i++) {
            if (last == k + i) {
                ans += num.substr(last);
                break;
            }
            int arg = argmin(num, last, k + i);
            if(num[arg] != '0' || ans.length())
                ans += num[arg];
            last = arg + 1;
        }
        ans = ans.length() ? ans : "0";
        return ans;
    }
};
//单调栈的应用,日后优化