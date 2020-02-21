class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size(),n2 = s.size();
        if(!n1 || !n2)
            return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int p1 = 0,p2 = 0;
        int cnt = 0;
        while(p2 < n2 && p1 < n1){
            if(g[p1] <= s[p2]){
                cnt++;
                p1++;
            }
            p2++;
        }
        return cnt;
    }
};