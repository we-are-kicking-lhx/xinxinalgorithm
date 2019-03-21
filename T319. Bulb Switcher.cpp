class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for(int i = 1; i * i <= n; i++){
            ans++;
        }
        return ans;
    }
};

//等价于
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};