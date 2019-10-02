class Solution {
public:
    int par[20002];
    int rank[20002] = {0};
    int find(int x){
        if (par[x] == x )
            return x;
        return par[x] = find(par[x]);
    }
    
    void unite(int x,int y){
        x = find(x);
        y = find(y);
        
        if (x == y)
            return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        }
        else{
            par[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < 20002; i++) {
            par[i] = i;
        }
        int max_i = -1,max_j = -1;
        for(auto i : stones){
            unite(i[0], i[1] + 10000);
            max_i = max(max_i,i[0]);
            max_j = max(max_j,i[1]);
        }
        int cnt = 0;
        for (auto i : stones) {
            int p = find(i[0]);
            if(rank[p] != -1){
                rank[p] = -1;
                cnt++;
            }
        }
        
        
        return stones.size() - cnt;
    }
};