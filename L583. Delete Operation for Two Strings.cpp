class Solution
{
  public:
    int dp[501][501] = {0};
    int minDistance(string word1, string word2)
    {
        for (int i = 1; i <= word1.length(); i++)
            for (int j = 1; j <= word2.length(); j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        return word1.length() + word2.length() - 2 * dp[word1.length()][word2.length()];
    }
};