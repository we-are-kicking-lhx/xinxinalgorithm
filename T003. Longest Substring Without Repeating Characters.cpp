//这是一个愚蠢的用马拉车对暴力解法实现的优化
//63ms 16M
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
//滑动窗口法，其实跑出来的结果和上面方法差不多 (52ms,16M)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0)return 0;
        int left = 0, right = 1,max = 1;
        map<int,int>m;
        m[s[0]] = 1;
        map<int,int>::iterator it;
        while (right < s.length()) {
            it = m.find(s[right]);
            if(it != m.end() && it->second != 0){
                while (s[left]!=s[right]) {
                    m[s[left]] = 0;
                    left++;
                }
                left++;
            }
            m[s[right]] = 1;
            max = right - left + 1 > max ? right - left + 1 : max;
            right++;
        }
        return max;
    }
};
//优化的滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(!n) return 0;
        unordered_map<char,int>hashmap;
        int left = 0,right = 1,max_len = 1;
        hashmap[s[0]] = 0;
        while(right < n){
            if(hashmap.count(s[right]) > 0){
                left = max(left,hashmap[s[right]]+1);
            } 
            max_len = max(right - left + 1,max_len);
            hashmap[s[right]] = right;
            right++;
        }
        return max_len;
    }

};