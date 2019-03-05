// LCS
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		string r_s(s);
		int a[1005][1005] = { 0 };
		reverse(r_s.begin(), r_s.end());
		for (int i = 1; i <= s.length(); i++)
			for (int j = 1; j <= s.length(); j++)
				if (s[i - 1] == r_s[j - 1]) a[i][j] = a[i - 1][j - 1] + 1;
				else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		return a[s.length()][s.length()];

	}
};