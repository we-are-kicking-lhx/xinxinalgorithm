class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string befor = "11";
        n = n - 2;
        while (n--) {
            string s = "";
            int count = 1;
            for (int i = 1; i < befor.length(); i++) {
                if (befor[i] == befor[i - 1])
                    count++;
                else{
                    s += to_string(count);
                    s += befor[i - 1];
                    count = 1;
                }
            }
            s += to_string(count);
            s += befor[befor.length() - 1];
            befor = s;
        }
        return befor;
    }
};