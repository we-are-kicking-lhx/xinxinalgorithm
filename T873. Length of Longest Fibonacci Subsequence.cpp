class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
    	int n = A.size();
    	int dp[1001][1001] = {};
    	int ans = 0;
    	unordered_map<int,int>index;
    	for(int i = 0;i < n;i++)
    		index[A[i]] = i;
    	for (int i = 0; i < n; ++i)
    	{
    		for (int j = i + 1; j < n; ++j)
    		{
                if(index.count(A[j] - A[i])){
                    if(index[A[j] - A[i]] < i){
                        dp[i][j] = max(dp[index[A[j] - A[i]]][i],2) + 1;
                        ans = max(ans,dp[i][j]);
                    }
                }
    		}
    	}
    	return ans;
    }
};