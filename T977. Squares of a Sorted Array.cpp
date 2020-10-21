class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left = 0,right = A.size()-1;
        vector<int>ans;
        while(left <= right){
            if(A[left] * A[left] >= A[right] * A[right]){
                ans.emplace_back(A[left]*A[left]);
                left++;
            }
            else{
                ans.emplace_back(A[right]*A[right]);
                right--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};