class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[1000][1000];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < s.length(); ++i){
            dp[i][i] = 1;
        }
        for (int len = 2; len <= s.length(); ++len)
        {
        	for (int i = 0; i + len -1 < s.length(); ++i)
        	{
        		int j = i + len -1;
        		if(s[i] == s[j]){
        			dp[i][j] = 2 + dp[i+1][j-1];
        		}
        		else{
        			dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
        		}
        	}
        }
        
        return dp[0][s.length()-1];
    }
};

//LPS Vedio Link:https://www.youtube.com/watch?v=_nCsPn7_OgI