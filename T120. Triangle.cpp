class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};
//O(n)的话关键点在行倒序遍历