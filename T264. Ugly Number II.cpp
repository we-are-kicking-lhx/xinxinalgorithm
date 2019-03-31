class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>v;
        v.push_back(1);
        int two = 0,three = 0,five = 0;
        for (int i = 1; i < n; i++) {
            int nxt = min(2 * v[two],min(3 * v[three],5 * v[five]));
            if (nxt == 2 * v[two]) two++;
            if (nxt == 3 * v[three]) three++;
            if (nxt == 5 * v[five]) five++;
            v.push_back(nxt);
        }
        return v[v.size()-1] ;
    }
};