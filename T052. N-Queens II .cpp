class Solution {
public:
    int solve(int n,int row,int col,int dia1,int dia2){
        if(row == n)
            return 1;
        int pos = ((1 << n) - 1) & (~(col|dia1|dia2));
        int cnt = 0;
        while(pos!=0){
            int pos0 = pos & (-pos);
            pos = pos & (pos - 1);
            cnt += solve(n,row+1,col | pos0,(dia1 | pos0) << 1, (dia2 | pos0) >> 1);
        }
        return cnt;
    }
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }
};