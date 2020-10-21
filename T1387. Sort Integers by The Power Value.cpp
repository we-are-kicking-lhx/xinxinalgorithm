typedef pair<int,int> P;
bool cmp(P x,P y){
    if(x.second != y.second)
        return x.second < y.second;
    return x.first < y.first;
}
class Solution {
    unordered_map<int,int>dp;
public:
    int getValue(int n){
        if(dp[n] == 0 && n != 1){
            if(n % 2 == 1)
                dp[n] = 1 + getValue(3 * n + 1);
            else
                dp[n] = 1 + getValue(n / 2);
        }
        return dp[n];
    }
    int getKth(int lo, int hi, int k) {
        vector<P>num;
        for(int i = lo;i <= hi; ++i){
            num.emplace_back(make_pair(i,getValue(i)));
        }
        sort(num.begin(),num.end(),cmp);

        
        return num[k-1].first;
    }
};