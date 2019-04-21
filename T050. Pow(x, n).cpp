class Solution {
public:
    double func(long n,double x){
        if(n==0) return 1;
        if(n % 2 != 0)
            return x * func(n - 1, x);
        double f = func(n/2, x);
        return f * f;
    }
    double myPow(double x, long n) {
        if (n < 0) {
            n = 0 - n;
            x = 1/x;
        }
        return func(n, x);
    }
};