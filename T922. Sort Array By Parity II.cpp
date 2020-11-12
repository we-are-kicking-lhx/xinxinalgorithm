class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int odd=1,even=0,n=A.size();
        for(;even<n;even=even+2){
            if(A[even]%2){
                while(odd<n&&A[odd]%2)
                    odd+=2;
                if(odd>=n)break;
                int temp = A[odd];
                A[odd] = A[even];
                A[even] = temp;
            }
        }
        return A;
    }
};