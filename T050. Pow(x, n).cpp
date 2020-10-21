class Solution {
public:
    double pow(double x, int n){
        if(n == 0)
            return 1.0;
        double half = pow(x,n / 2);
        if(n % 2)
            return x * half * half;
        return half * half;
    }
    double myPow(double x, int n) {
        long long ln = n;
        if(ln < 0){
            x = 1 / x;
            ln = -ln;
        }
        return pow(x,ln);
    }
};