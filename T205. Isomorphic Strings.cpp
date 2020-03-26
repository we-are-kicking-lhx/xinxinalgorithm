class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>hashmap_s,hashmap_t;
        int n = s.length();
        for(int i = 0; i < n; ++i){
            if(hashmap_s.count(s[i]) > 0){
                if(hashmap_s[s[i]] != t[i])
                    return false;
                continue;
            }
            if(hashmap_t.count(t[i]) > 0){
                if(hashmap_t[t[i]] != s[i])
                    return false;
                continue;
            }
            hashmap_s[s[i]] = t[i];
            hashmap_t[t[i]] = s[i];
        }
        return true;
    }
};
//还可以映射到位置