class Solution {
public:
    string addBinary(string a, string b) {
        int up = 0;
        int na = a.length(),nb = b.length();
        string res = "";
        while(na > nb){
            b = "0" + b;
            nb++;
        }
        while(nb > na){
            a = "0" + a;
            na++;
        }
        int p = na - 1;
        while(p >= 0){
            res  = to_string((a[p] - '0')^(b[p] - '0')^up) + res;
            if(a[p] - '0' + b[p] - '0' + up > 1)
                up = 1;
            else
                up = 0;
            p--;
        }
        if(up)res = "1" + res;
        return res;



    }
};