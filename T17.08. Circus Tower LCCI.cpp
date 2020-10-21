bool cmp(pair<int,int>x,pair<int,int>y){
    if(x.first!=y.first)return x.first < y.first;
    return x.second > y.second;
}
class Solution {
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int,int>>v;
        for(int i = 0;i < height.size();i++)
            v.emplace_back(make_pair(height[i],weight[i]));
        sort(v.begin(),v.end(),cmp);
        int ans[10001],cnt = 1;
        ans[1] = v[0].second;
        for(int i = 1;i < height.size();i++){
            if(v[i].second > ans[cnt])
                ans[++cnt] = v[i].second;
            else if(v[i].second < ans[cnt]){
                int pos = lower_bound(ans+1,ans+1+cnt,v[i].second) - ans;
                ans[pos] = v[i].second;
            }
        }
        return cnt;
    }
};