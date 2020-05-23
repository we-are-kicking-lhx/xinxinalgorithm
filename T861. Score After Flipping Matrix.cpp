class Solution {
public:
    int bitToDecimal(vector<int>bit){
        int ans = 0;
        for(int i : bit)
            ans = (ans << 1) + i;
        return ans;
    }
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        for(int r = 0;r < n;r++){
            if(A[r][0] == 0){
                for(int &i : A[r])
                    i ^= 1;
            }
        }

        for(int c = 1;c < m;c++){
            int sum = 0;
            for(auto r : A)
                sum += r[c];
            if(sum < n - sum){
                for(auto &i : A)
                    i[c] ^= 1;
            }
        }
        int sum = 0;
        for(auto r : A)
            sum += bitToDecimal(r);
        return sum;
    }
};

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();

        for(int r = 0;r < n;r++){
            if(A[r][0] == 0){
                for(int &i : A[r])
                    i ^= 1;
            }
        }
        int ans = n;
        for(int c = 1;c < m;c++){
            int sum = 0;
            for(auto r : A)
                sum += r[c];
            ans = (ans << 1) + max(sum,n - sum);
        }
        return ans;
    }
};