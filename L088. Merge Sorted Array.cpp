class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1, j = n - 1, k = m + n - 1;
		while (i >= 0 && j >= 0) {
			if (nums1[i] > nums2[j]) {
				nums1[k] = nums1[i];
				i--; 
			}
			else if (nums1[i] < nums2[j]) {
				nums1[k] = nums2[j];
				j--; 
			}
			else {
				nums1[k] = nums1[k - 1] = nums1[i];
				k--; i--; j--;
			}
			k--;
		}
		if (j >= 0) {
			for (int p = 0; p <= j; p++) {
				nums1[p] = nums2[p];
			}
		}
	}
};