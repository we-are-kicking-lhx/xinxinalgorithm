class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0,right = n - 1;
        while(left < right){
            int ans = numbers[left] + numbers[right];
            if(ans == target)
                return{left + 1,right + 1};
            if(ans < target)
                left++;
            else
                right--;
        }
        return {0};
    }
};