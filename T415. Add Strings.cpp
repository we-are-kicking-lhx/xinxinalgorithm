class Solution {
public:
    string addStrings(string num1, string num2) {
        int up = 0;
        int n1 = num1.length(),n2 = num2.length();
        string res = "";
        while(n1 > n2){
            num2 = "0" + num2;
            n2++;
        }
        while(n2 > n1){
            num1 = "0" + num1;
            n1++;
        }
        int p = n1 - 1;
        while(p >= 0){
            res  = to_string(((num1[p] - '0')+(num2[p] - '0')+up)%10) + res;
            if(num1[p] - '0' + num2[p] - '0' + up >= 10)
                up = 1;
            else
                up = 0;
            p--;
        }
        if(up)res = "1" + res;
        return res;
    }
};