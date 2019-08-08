class Solution {
public:
    vector<vector<char>> v;
    int row,col,cnt =0;
    void infect(int x,int y){
        if (x < 0 || y < 0 || x >= row || y >= col)
            return;
        if (v[x][y] != '1')
            return;
        v[x][y] = '2';
        infect(x + 1, y);
        infect(x, y + 1);
        infect(x, y - 1);
        infect(x - 1, y);
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        if (!row) return 0;
        col = grid[0].size();
        for (auto i : grid) {
            vector<char> row;
            for(auto j : i)
                row.push_back(j);
            v.push_back(row);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0 ; j < col; j++) {
                if (v[i][j] == '1'){
                    cnt++;
                    infect(i, j);
                }
            }
        }
        return cnt;
    }
};