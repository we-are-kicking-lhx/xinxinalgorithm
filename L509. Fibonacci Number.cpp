class Solution {
public:
    int fib(int n) {
        long long a=0,b=1;
        for(int i=0;i<n;i++){
            b=a+b;
            a=b-a;
            a=a%(1000000007);
            b=b%(1000000007);
        }
        return a%(1000000007);
    }
};