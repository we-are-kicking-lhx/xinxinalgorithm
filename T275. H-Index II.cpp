class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n)
            return 0;
        if(citations[n - 1] == 0)
            return 0;
        int left = 0,right = n - 1;
        int mid;
        while (left <= right) {
            mid = (left + right)/2;
            if(citations[mid] < n - mid)
                left = mid + 1;
            else if(citations[mid] > n - mid) {
                right = mid - 1;
            }
            else
                return n - mid;
        }
        return n - left;
    }
};