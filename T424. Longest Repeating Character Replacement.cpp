class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0,right = 0,len = s.length(),max_len = 1,ans = 1;
        if(!len) return 0;
        int dict[26] = {0};
        dict[s[0] - 'A']++;
        while (++right < len) {
            max_len = max(max_len,++dict[s[right] - 'A']);
            if (right - left + 1 - max_len > k)
                dict[s[left++] - 'A']--;
            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};
//滑动窗口