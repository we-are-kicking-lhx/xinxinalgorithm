class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int ans=0,i=0,j=0;
        set<char> se;
        while(i<len && j<len){
            if(se.find(s[j])==se.end()) {se.insert(s[j++]);ans=max(ans,j-i);}
            else se.erase(s[i++]);
        }
        return ans;
    }
};