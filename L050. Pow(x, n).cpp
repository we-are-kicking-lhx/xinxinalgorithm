class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        int i=n;
        while(i){
            if(i%2!=0) ans*=x;
            x*=x;
            i/=2;
        }
        return n>0?ans:1.0/ans;
    }
};