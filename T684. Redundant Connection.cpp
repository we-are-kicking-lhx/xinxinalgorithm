class Solution {
public:
    int par[1002];
    int rank[1002] = {0};
    int find_g(int x){
        if (par[x] == x)
            return x;
        else
            return par[x] = find_g(par[x]);
    }
    void unite(int x,int y){
        x = find_g(x);
        y = find_g(y);
        if (x == y)
            return;
        if (rank[x] < rank[y])
            par[x] = y;
        else{
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int r;
        int n = edges.size();
        for (int i = 1; i <= n; i++) {
            par[i] = i;
        }
        for (int i = 0 ; i < n; i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            if (find_g(x) == find_g(y))
                r = i;
            else
                unite(x, y);
        }
        return edges[r];
    }
};