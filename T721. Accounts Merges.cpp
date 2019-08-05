const int maxn = 1002;
typedef pair<string,int> P;
class Solution {
public:
    int par[maxn];
    int rank[maxn];
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int visit[maxn] ;
        for (int i = 0; i < n; i++) {
            visit[i] = -1;
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        map<string,int>m;
        map<string,int>::iterator it;
        for (int i = 0;i < n; i++) {
            int cnt = 0;
            for (auto mail : accounts[i]) {
                if (!cnt) {
                    cnt = 1;
                    continue;
                }
                it = m.find(mail);
                if (it == m.end())
                    m.insert(P(mail,i));
                else
                    union_g(it->second, i);
            }
        }
        int cnt = 0;
        for (auto me : m) {
            int g = find_g(me.second);
            if (visit[g]==-1) {
                visit[g] = cnt++;
                vector<string>r;
                r.push_back(accounts[g][0]);
                r.push_back(me.first);
                res.push_back(r);
            }
            else
                res[visit[g]].push_back(me.first);
        }
        return res;
    }
};