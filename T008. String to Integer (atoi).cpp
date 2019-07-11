//1.耿直解法
const int int_max = 2147483647;
const int int_min = -2147483648;
class Solution {
public:
    int myAtoi(string str) {
        int s = 0;
        int sub = 1;
        for(int i = 0;i < str.length();i++){
            if (isdigit(str[i]) || str[i] == '+' || str[i] == '-') {
                s = i;
                break;
            }
            if(str[i]!=' ')
                return 0;
        }
        if(str[s] == '-' || str[s] == '+'){
            if(str[s] == '-')sub = -1;
            s += 1;
        }
        int res = 0;
        int cnt = 0;
        while (s < str.length() && isdigit(str[s])) {
            int pop = str[s++] - '0';
            if(pop || res)cnt += 1;
            if(cnt > 10){
                if(sub == -1)return int_min;
                return int_max;
            }
            if(cnt == 10){
                if(res < int_min/10 || res == int_min/10 && pop > 8)
                        return int_min;
                else if(res > int_max/10 || res == int_max/10 && pop > 7)
                    return int_max;
            }
            res = res * 10 + sub * pop;
        }
        return res;
    }
};


//2.作弊解法
class Solution {
public:
    int myAtoi(string str) {
        while(*str.begin() == ' ') str.erase(str.begin());
        if(str == "") return 0;
        stringstream ss;
        ss<<str;
        int n;
        ss>>n;
        return n;
    }
};
