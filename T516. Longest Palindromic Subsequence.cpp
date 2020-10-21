//方法1 
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1005][1005];
        int n = s.length();
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
        
    }
};

//方法2
//逆序 再LCS 要比第一种慢
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1005][1005];
        dp[0][0] = 0;
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(s[i] == s1[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[n][n];
        
    }
};

