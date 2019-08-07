class Solution {
public:
    int par[26];
    int rank[26] = {0};
    int find_g(int x){
        if (par[x] == x)
            return x;
        else
            return par[x] = find_g(par[x]);
    }
    void union_g(int x,int y){
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
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        for (int i = 0; i < 26; i++) {
            par[i] = i;
        }
        for (auto e : equations) {
            if (e[1] == '=')
                union_g(e[0] - 'a', e[3] - 'a');
        }
        for (auto e : equations) {
            if (e[1] == '!') {
                if (find_g(e[0] - 'a') == find_g(e[3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};