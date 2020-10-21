class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int a[26] = {};
        for(int i = 0;i < 26; ++i)
            a[i] = 200;
        for(auto s : A){
            int n[26] = {0};
            for(char c : s)
                n[c-'a']++;
            for(int i = 0;i < 26; ++i)
                a[i]=min(n[i],a[i]);
        }
        vector<string>ans;
        for(int i = 0;i < 26; ++i){
            if(a[i]!=200){
                while(a[i]--){
                    ans.emplace_back(1,'a'+i);
                }
            }
        }
        return ans;
    }
};