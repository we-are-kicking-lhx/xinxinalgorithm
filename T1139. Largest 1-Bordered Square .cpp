class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<vector<vector<int>>>dp(n + 1,vector<vector<int>>(m + 1,vector<int>(2,0)));
        int maxlen = 0;
        for(int i = 1;i <= n; i++){
            for(int j = 1;j <= m; j++){
                if(grid[i-1][j-1]){
                    dp[i][j][0] = dp[i - 1][j][0] + 1;//上
                    dp[i][j][1] = dp[i][j - 1][1] + 1;//左
                }
                int len = min(dp[i][j][0],dp[i][j][1]);
                if(len > maxlen){
                    while(len - 1 > 0){
                        if(dp[i][j - len + 1][0] >= len && dp[i - len + 1][j][1] >= len)
                            break;
                        len--;
                    }
                    maxlen = max(maxlen,len);
                }
            }
        }
        return maxlen * maxlen;
    }
};