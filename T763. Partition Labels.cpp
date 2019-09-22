class Solution {
public:
    vector<int> partitionLabels(string S) {
        int a[26] = {0};
        vector<int> res;
        for (int i = 0; i < S.length(); i++)
            a[S[i] - 'a'] = i;
        int l = 0,r,s;
        while (l < S.length()) {
            s = l;
            r = a[S[l] - 'a'];
            while (l < r) {
                if (a[S[l] - 'a'] > r)
                    r = a[S[l] - 'a'];
                l++;
            }
            res.push_back(r - s + 1);
            l++;
        }
        return res;
    }
};