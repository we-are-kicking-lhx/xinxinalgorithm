class Solution {
public:
    int getK(vector<int>& nums1, vector<int>& nums2,int k,int l1,int l2){
        if(l1 == nums1.size())
            return nums2[l2 + k - 1];
        if(l2 == nums2.size())
            return nums1[l1 + k - 1];
        if(k == 1)
            return min(nums1[l1],nums2[l2]);
        int e1 = min((int)nums1.size() - 1,l1 + k/2 - 1);
        int e2 = min((int)nums2.size() - 1,l2 + k/2 - 1);
        if(nums1[e1] < nums2[e2])
            return getK(nums1, nums2,k - (e1 - l1 + 1),e1 + 1,l2);
        else
            return getK(nums1, nums2,k - (e2 - l2 + 1),l1,e2 + 1);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        // cout << getK(nums1,nums2,3,0,0) << endl;
        if((n + m) % 2 == 0)
            return (getK(nums1,nums2,(n+m)/2,0,0) * 1.0 + getK(nums1,nums2,(n+m)/2+1,0,0)) / 2;
        else
            return getK(nums1,nums2,(n+m+1)/2,0,0);
    }
};