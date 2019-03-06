// A(m+n-2,m+n-2)/(A(m-1,m-1)*A(n-1,n-1))=c(m+n-2,n-1) n<m
class Solution {
public:
	int uniquePaths(int m, int n) {
		int a = min(m, n) - 1;
		int b = m + n - 2 - a;
		long long x = 1, y = 1;
		for (int i = 0; i < a; i++) {
			x *= a + b - i; y *= 1 + i;
			if (x%y == 0) {
				x = x / y; y = 1;
			}
		}
		return x / y;
	}
};
// dp
class Solution {
public:
	int uniquePaths(int m, int n) {
		int dp[101][101];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++) {
				if (i == 1 || j == 1)dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		return dp[m][n];
	}
};
