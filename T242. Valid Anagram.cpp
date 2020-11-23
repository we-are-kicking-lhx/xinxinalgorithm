class Solution {
public:
    string strtoseq(string s){
        int a[26] = {};
        for(auto c : s)
            a[c -'a']++;
        string ans = "";
        for(int i = 0;i < 26; ++i){
            ans += to_string(a[i]);
            ans += "#";
        }
        return ans;
    }
    bool isAnagram(string s, string t) {
        return strtoseq(s)==strtoseq(t);
    }
};