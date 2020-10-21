class Solution {
public:
    int findIndex(vector<char>&nums){
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right])
                right = mid;
            else if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right--;
        }
        if(left == 0 && nums[left] == nums[n - 1]){
            for(int i = n - 2; i >= 0; --i){
                if(nums[i] != nums[i + 1]){
                    left = i + 1;
                    break;
                }  
            }
        }
        return left;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int index = findIndex(letters);
        int pos;
        if(index == 0)
            pos = upper_bound(letters.begin(),letters.end(),target) - letters.begin();
        else{
            if(letters[n - 1] <= target){
                pos = upper_bound(letters.begin(),letters.begin() + index,target) - letters.begin();
                cout << pos;
            }
            else{
                pos = upper_bound(letters.begin() + index,letters.end(),target) - letters.begin() - index;
            }
        }
        return letters[pos % n]; 
    }
};