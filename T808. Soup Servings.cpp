class Solution {
public:
    vector<vector<double>>dp;
    double serve(int a,int b){
        if(a <= 0)
            return b <= 0 ? 0.5 : 1;
        if(b <= 0)
            return 0;
        if(dp[a][b] == 0){
            double f,s,t,fr;
            f = serve(a - 4,b);
            s = serve(a - 3,b - 1);
            t = serve(a - 2,b - 2);
            fr = serve(a - 1,b - 3);
            dp[a][b] = 0.25 * (f + s + t + fr);
        }
        return dp[a][b];
    }
    double soupServings(int N) {
        if(N>6000)return 1;
        N = (N+24)/25;
        dp = vector(N + 1,vector<double>(N + 1,0));
        return serve(N,N);
    }
};