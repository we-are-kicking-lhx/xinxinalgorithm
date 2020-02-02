class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n =  heaters.size();
        sort(heaters.begin(),heaters.end());
        int res = 0;
        for (auto h : houses) {
            int pos = lower_bound(heaters.begin(), heaters.end(), h) - heaters.begin();
            int len;
            if(pos == 0)
                len = heaters[pos] - h;
            else if(pos == n)
                len = h - heaters[pos - 1];
            else
                len = min(heaters[pos] - h,h - heaters[pos - 1]);
            res = max(res,len);
        }
        return res;
    }
};