class Solution {
public:
    int par[2000] = {0};
    int rank[2000] = {0};
    int find(int x){
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void union_f(int x,int y){
        x = find(x);
        y = find(y);
        if(x == y)
            return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        }
        else{
            par[y] = x;
            if (rank[x] == rank[y])rank[x]++;
        }
    }
    
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        if (!n)
            return 0;
        int res = 0;
        for (int i = 0; i < n*(n+1); i++) {
            par[i] = i;
            par[1000 + i] = i + 1000;
        }
        string s = "\\/ ";
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0 ; j < grid[0].length(); j++) {
                if(grid[i][j] == s[0]){
                    union_f(i*n+j, i*(n+1)+j+1000+1);
                    union_f(i*(n+1)+j+1000, (i+1)*n+j);
                }
                else if(grid[i][j] == s[1]){
                    union_f(i*n+j, i*(n+1)+j+1000);
                    union_f(i*(n+1)+j+1000+1, (i+1)*n+j);
                }
                else{
                    union_f(i*n+j, i*(n+1)+j+1000);
                    union_f(i*(n+1)+j+1000+1, (i+1)*n+j);
                    union_f(i*n+j, i*(n+1)+j+1000+1);
                }
                
            }
            
        }
        int visited[2000] = {0};
        for (int i = 0; i < n*(n+1); i++) {
            int r = find(i);
            if (visited[r] == 0) {
                res++;
                visited[r] = 1;
            }
            r = find(1000+i);
            if (visited[r] == 0) {
                res++;
                visited[r] = 1;
            }
        }
        return res;
    }
};