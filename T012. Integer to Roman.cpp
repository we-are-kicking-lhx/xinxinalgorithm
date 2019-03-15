class Solution {
public:
    string intToRoman(int num) {
        map<int,string>m;
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";
        string s = "";
        int x = 1000, times = 4, n = num;
        while (times) {
            int t = n / x;
            if(t == 9 || t == 4 || t == 5)
                s += m[x * t];
            else {
                int cnt = t;
                if(cnt > 5){
                    s += m[x * 5];
                    cnt -= 5;
                }
                while (cnt) {
                    s += m[x];
                    cnt--;
                }
            }
            times--;
            n = n - t * x;
            x /= 10;
        }
        return s;
    }
};
