class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp = vector<int>(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n; i++){
            for(auto word : wordDict){
                int len = word.length();
                if(i >= len){
                    if(!s.compare(i-len,len,word)&&dp[i-len]){
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