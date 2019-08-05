class Solution {
public:
    vector<vector<char>> v;
    void infect(int x,int y){
        int row = v.size(),col = v[0].size();
        if (x < 0 || x >= row || y < 0 || y >= col)
            return;
        if (v[x][y] != 'O') {
            return;
        }
        v[x][y] = 't';
        infect(x, y + 1);
        infect(x, y - 1);
        infect(x - 1, y);
        infect(x + 1, y);
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return;
        int m = board[0].size();
        for (auto r : board) {
            vector<char> c;
            for (auto e : r) {
                c.push_back(e);
            }
            v.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            if (v[i][0] == 'O')
                infect(i, 0);
            if (v[i][m-1] == 'O' )
                infect(i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            if (v[0][i] == 'O')
                infect(0, i);
            if (v[n-1][i] == 'O' )
                infect(n-1,i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(v[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};