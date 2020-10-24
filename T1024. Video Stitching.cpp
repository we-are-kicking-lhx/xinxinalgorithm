class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int maxn[101] = {};
        for(auto c : clips)
            maxn[c[0]] = max(c[1],maxn[c[0]]);
        int ans = 0,next = 0,prev = 0;
        for(int i = 0;i < T; ++i){
            next = max(maxn[i],next);
            if(next == i)
                return -1;
            if(prev == i){
                ans++;
                prev = next;
            }
        }
        return ans;
    }
};