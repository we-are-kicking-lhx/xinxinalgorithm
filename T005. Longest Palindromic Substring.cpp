class Solution {
public:
    string longestPalindrome(string s) {
        int p[2005] = {0};
        int mx = 0, id = 0, center = 0, len = 0;
        string s1 = "$#";
        for (int i = 0; i < s.length(); ++i)
        {
        	s1 += s[i];
        	s1 += "#";
        }

        for (int i = 1; i < s1.length() - 1; ++i)
        {
        	p[i] = mx > i ? min(mx - i, p[2*id - i]) : 1;
        	while(s1[i - p[i]] == s1[i + p[i]]) p[i]++;
        	if (p[i] + i > mx){
        		mx = p[i] + i;
        		id = i;
        	}

        	if(p[i] > len){
        		len = p[i];
        		center = i;
        	}
        }
        return s.substr((center - len)/2,len - 1);
    }
};
