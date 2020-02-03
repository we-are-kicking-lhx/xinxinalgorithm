class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int left = 0,right = n - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if(A[mid] < A[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
       return left;
        // cout << left <<" "<< right << endl;
        // return 0;
    }
};