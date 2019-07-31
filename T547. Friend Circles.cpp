class Solution {
public:
    int par[202];
    int rank[202] = {0};
    int N;
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
        N--;
        if (rank[x] < rank[y])
            par[x] = y;
        else{
            par[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        N = n;
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0 ; j < i; j++) {
                if (M[i][j])
                    unite(i, j);
            }
        }
        return N;
    }
};