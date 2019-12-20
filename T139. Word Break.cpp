class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp = vector<int>(n+1,0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (auto word : wordDict) {
                int len = word.size();
                if(i >= len){
                    if(!s.compare(i-len, len, word) && dp[i-len]){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        if(dp[n])return true;
        return false;
    }
};

// dp[i]指的是长度为i的字符是否能被表达所以 dp[1]表示的是s(0,0)能被表达
