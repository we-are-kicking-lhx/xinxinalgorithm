class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string res="";
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>strs.size() || ch != strs[j][i])
                    return res;
            }
            res+=ch;
        }
        return res;
    }
};