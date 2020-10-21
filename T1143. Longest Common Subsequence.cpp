class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1005][1005] = {0};
        for (int i = 0; i < text1.length(); i++) {
            for (int j = 0; j < text2.length(); j++) {
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};