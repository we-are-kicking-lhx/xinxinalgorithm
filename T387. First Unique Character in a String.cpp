class Solution {
public:
    int firstUniqChar(string s) {
        int hashmap[26] = {};
        for(char c : s)
            hashmap[c - 'a']++;
        for(int i = 0;i < s.length();i++){
            if(hashmap[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
