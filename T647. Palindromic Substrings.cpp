class Solution {
public:
    int countSubstrings(string s) {
        int p[2005] = {0};
        int max = 0, id = 0;
        int times = s.length();
        string s1 = "$#";
        for (int i = 0; i < s.length(); ++i)
        {
            s1 += s[i];
            s1 += "#";
        }
        
        for (int i = 1; i < s1.length() - 1; ++i)
        {
            p[i] = max > i ? min(max - i, p[2*id - i]) : 1;
            while(s1[i - p[i]] == s1[i + p[i]]) p[i]++;
            if (p[i] + i > max){
                max = p[i] + i;
                id = i;
            }
            times += p[i] > 0 ? (p[i] - 1)/2 : 0;
            
        }
        return times;
    }
};
//马拉车算法改的
//(p[i]-1)/2 是以每个字符为中心的回文串个数，求和再加上原字符长度就是所求