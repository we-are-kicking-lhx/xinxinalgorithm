class Solution {
public:
    int romanToInt(string s) {
        map<char, int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int last = 1001;
        int res = 0;
        for(auto c : s){
            if(m[c] > last)
                res += m[c] - 2 * last;
            else
                res += m[c];
            last = m[c];
        }
        return res;
    }
};