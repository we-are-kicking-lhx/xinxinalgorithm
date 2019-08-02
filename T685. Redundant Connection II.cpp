const int maxn = 1002;
class Solution {
public:
    int par[maxn];
    int rank[maxn] = {0};
    int find_g(int x){
        if(par[x] == x)
            return x;
        else return par[x] = find_g(par[x]);
    }
    
    int union_g(int x,int y){
        x = find_g(x);
        y = find_g(y);
        if(x == y)
            return 1;
        if (rank[x] < rank[y])
            par[x] = y;
        else{
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
        return 0;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> r;
        for (int i = 1; i <= n; i++)
            par[i] = i;
        vector<vector<int>>degree = vector<vector<int>>(n+1);
        int a[maxn] = {0},node = -1,res;
        //记录结点入度
        for(auto e : edges){
            degree[e[1]].push_back(e[0]);
            if(a[e[1]]++){
                node = e[1];
            }
        }
        //情况一：存在入度为2的结点。去除顺序在后的入度边判断是否存在环。
        if (node != -1) {
            res = degree[node][1];
            degree[node].pop_back();
            int has_circle = 0;
            for (int i = 1;i <= n;i++) {
                if(degree[i].size()){
                    if (union_g(i, degree[i][0])) {
                        has_circle = 1;
                        break;
                    }
                }
            }
            if (has_circle)
                return {degree[node][0],node};
            else
                return {res,node};
        }
        //情况二：存在环。去除顺序在后的环中的边。
        for (auto e : edges) {
            if (union_g(e[0], e[1])) {
                return e;
            }
        }
        return r;
    }
};