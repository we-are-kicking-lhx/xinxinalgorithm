class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		int x1, y1, x2, y2;
		str2nums(a, x1, y1);
		str2nums(b, x2, y2);
		return to_string(x1*x2 - y1 * y2) + "+" + to_string(x1*y2 + x2 * y1) + "i";
	}
	void str2nums(string s, int &x, int &y) {
		int n = 0;
		while (s[n++] != '+');
		x = stoi(s.substr(0, n-1));
		y = stoi(s.substr(n, s.length() - n - 1));
	}
};