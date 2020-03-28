//双指针、排序
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0,p2 = 0;
        vector<int>res;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums2[p2]);
                p1++;
                p2++;
            }
            else if(nums1[p1] > nums2[p2])
                p2++;
            else
                p1++;
        }
        return res;
    }
};
//hashmap
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        unordered_map<int,int>hashmap;
        for(auto i : nums1){
            if(hashmap.count(i) > 0)
                hashmap[i]++;
            else
                hashmap[i] = 1;
        }
        for(auto i : nums2){
            if(hashmap.count(i) > 0){
                if(hashmap[i] >= 1){
                    hashmap[i]--;
                    res.push_back(i);
                }
            }
        }
        return res;
        
    }
};

/*进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？*/


//如果已经排好序，肯定是使用双指针最优，线性时间复杂度，没有额外空间
//如果小很多，但未排序，取第二种hash方法，将小的数组进行遍历（节省空间），时间复杂度O(m+n)，空间复杂度O(min(m,n))
//先排序写进外存然后分批加载？
