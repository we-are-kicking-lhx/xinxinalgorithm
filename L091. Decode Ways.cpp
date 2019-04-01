class Solution
{
  public:
    int numDecodings(string s)
    {
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            if (s[i - 1] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp[dp.size() - 1];
    }
};