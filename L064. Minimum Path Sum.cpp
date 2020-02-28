class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>dp(n);
        dp[n-1]=grid[m-1][n-1];
        for(int i=n-1;i>0;i--) dp[i-1]=grid[m-1][i-1]+dp[i];
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(j==n-1) dp[j]+=grid[i][j];
                else dp[j]=min(dp[j+1],dp[j])+grid[i][j];
            }
        }
        return dp[0];
    }
};
// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,0));
//         dp[0][0]=grid[0][0];
//         for(int i=1;i<n;i++) dp[0][i]=grid[0][i]+dp[0][i-1];
//         for(int i=1;i<m;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };