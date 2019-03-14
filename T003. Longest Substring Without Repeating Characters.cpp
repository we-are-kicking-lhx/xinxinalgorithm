//这是一个愚蠢的用马拉车对暴力解法实现的优化
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0)return 0;
        int max = 1;
        vector<int>p = vector<int>(s.size(),0);
        map<int,int>m;
        int mx = 0, id = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if(mx > i){
                p[i] = p[id] - (i - id);
                for (int k = id; k < i; k++) {
                    m[s[k] - 'a'] = 0;
                }
            }
            else {
                p[i] = 1;
                map<int,int>::iterator it;
                for (it = m.begin(); it != m.end(); it++) {
                    it->second = 0;
                }
            }
            m[s[i] - 'a'] = 1;
            for (int j = i + p[i] ; j < s.length(); j++) {
                if(m[s[j] - 'a'] == 0)
                {
                    p[i]++;
                    m[s[j] - 'a'] = 1;
                }
                else break;
            }
            if(p[i] + i > mx){
                mx = p[i] + i - 1;
                id = i;
            }
            if(p[i] > max) max = p[i];
            if(s.length() - 1 - i - 1 < max)break;
            
        }
        
        return max;
    }
};
//理想解法应该是滑动窗口法，明日改