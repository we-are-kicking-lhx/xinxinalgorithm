#include<vector>
using namespace std;
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() < 2)return s;
		string re = s.substr(0, 1);
		for (int i = 0; i < s.length(); i++) {
			string temp;
			temp = fun(i, i, s);
			if (temp.length() > re.length()) re = temp;
			temp = fun(i, i + 1, s);
			if (temp.length() > re.length()) re = temp;
		}
		return re;
	}
	string fun(int i, int j, string s) {
		while (i >= 0 && j < s.length() && s[i] == s[j]) {
			i--; j++;
		}
		return s.substr(i + 1, j - i - 1);
	}
};
};
int main() {
	string s = "babad";
	Solution d;
	d.longestPalindrome(s);
}