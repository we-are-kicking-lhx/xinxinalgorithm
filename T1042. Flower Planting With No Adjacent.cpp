class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>>g(N+1);
        for(auto i : paths){
            g[max(i[0],i[1])].emplace_back(min(i[0],i[1]));
        }
        vector<int>ans(N,0);
        for(int i = 1;i <= N;i++){
            int mark[] = {1,1,1,1};
            for(auto j : g[i]){
                mark[ans[j-1]-1] = 0;
            }
            for(int k = 0;k < 4;k++){
                if(mark[k]){
                    ans[i-1] = k + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
