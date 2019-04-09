class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int ans = 0;
        int left = 0, right = 1, diff = A[1] - A[0];
        while (++right < A.size()) {
            if(A[right] - A[right - 1] != diff){
                if(right - left >= 2){
                    ans += (1 + (right - left - 2)) * (right - left - 2) / 2;
                    left = right - 1;
                }
            }
            diff = A[right] - A[right - 1];
        }
        if(right - left >= 2)
            ans += (1 + (right - left - 2)) * (right - left - 2) / 2;
        return ans;
    }
};