class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()==1) return 1;
        int flag = A[0] > A[1];
        int dp[40000];
        dp[0] = 1;
        dp[1] = A[0] == A[1] ? 1 : 2;
        int len = dp[1];
        for (int i = 2; i < A.size(); i++) {
            if(A[i - 1] == A[i]){
                len = len > dp[i - 1] ? len : dp[i - 1];
                dp[i] = 1;
            }
            else if((A[i - 1] > A[i]) ^ flag)
                dp[i] = dp[i - 1] + 1;
            else{
                len = len > dp[i - 1] ? len : dp[i - 1];
                dp[i] = 2;
            }
            flag = A[i - 1] > A[i];
        }
        len = len > dp[A.size() - 1] ? len : dp[A.size() - 1];
        return len;
    }
};
