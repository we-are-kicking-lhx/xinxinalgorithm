class Solution {
public:
    vector<int> partitionLabels(string S) {
        int a[26] = {0};
        int l = 0,r,n = S.length(),cnt=0;
        for(int i = 0;i < n; ++i)
            a[S[i]-'a'] = i;
        r = a[S[l]-'a'];
        vector<int>ans;
        while(l < n){
            cnt++;
            if(l == r){
                ans.emplace_back(cnt);
                if(l < n - 1){
                    r = a[S[l+1]-'a'];
                    cnt = 0;
                }
            }
            else
                r = max(r,a[S[l]-'a']);
            l++;
        }
        return ans;
    }
};