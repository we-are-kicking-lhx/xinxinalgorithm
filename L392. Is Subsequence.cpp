class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i=0;
        for(int j=0;j<s.size();j++){
            size_t ind=t.find(s[j],i);
            if(ind==string::npos) return false;
            i=ind+1;
        }
        return true;
    }
};