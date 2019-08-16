class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int cnt = 0;
        if (!n) return 0;
        for (int right = 0,left = 0; right < n; right++) {
            if (!A[right] && !K){
                while (A[left]) {
                    left++;
                }
                left++;
            }
            else if(!A[right])K--;
            cnt = max(cnt,right - left + 1);
        }
        return cnt;
    }
};
//right表示]还是）前后要一致，一般都是]
//不要贪图更新的次数降低而漏掉某些需要更新的地方