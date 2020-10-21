//1.调用库函数
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it_s = lower_bound(nums.begin(),nums.end(),target);
        if(it_s == nums.end() || *it_s != target)
            return {-1,-1};
        auto it_e = upper_bound(nums.begin(),nums.end(),target) - 1;
        return {(int)(it_s - nums.begin()),(int)(it_e - nums.begin())};
    }
};

//2.实现库函数,但是↓
class Solution {
public:
    int mix_bound(vector<int>& nums,int target,int upper = 0){
        int n = nums.size();
        int left = 0,right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target || upper && nums[mid] == target)//upper=1时是upper_bound
                left = mid + 1;
            else
                right = mid;
        }
        cout << left << endl;
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int leftIndex = mix_bound(nums,target);
        if(leftIndex == n || nums[leftIndex] != target)
            return{-1,-1};
        int rightIndex = mix_bound(nums,target,1) - 1;
        return {leftIndex,rightIndex};
    }
};
//这并不是真实的lowerbound等的实现
//lowerbound和upperbound的区别在于nums[mid]==target时应该收缩左边界还是右边界
//上述函数通过upper == 1与否确定该收缩哪个边界
//与原本实现不同的是，真实lowerbound收缩右边界时不全是只移动到mid，在nums[mid]>target时会收缩到mid - 1