class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        vector<int>v = vector<int>(n,0);
        int res = 0;
        for (int i = 0;i < n;i++){
            v[i] = customers[i] * grumpy[i];
            if (grumpy[i] == 0)
                res += customers[i];
        }
        int left = 0,right = 0,res2 = 0;
        while (right < n) {
            int N = X,r = 0;
            while (left < n && !v[left]) {
                left++;
            }
            for (right = left; N-- && right < n; right++) {
                r += v[right];
            }
            res2 = res2 > r ? res2 : r;
            left++;
            
        }
        return res + res2;
    }

};