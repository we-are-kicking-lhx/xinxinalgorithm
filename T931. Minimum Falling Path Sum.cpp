class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int row = A.size();
        int col = A.size();
        int ans[101];
        for (int i = 0; i < col; i++) {
            ans[i] = A[0][i];
        }
        for (int i = 1; i < col; i++) {
            int lst,now;
            for (int j = 0; j < col; j++) {
                now = ans[j];
                if (j)
                    ans[j] = min(lst, ans[j]);
                if (j + 1 < col)
                    ans[j] = min(ans[j + 1], ans[j]);
                ans[j] += A[i][j];
                lst = now;
            }
        }
        return * min_element(ans, ans + col);
    }
};