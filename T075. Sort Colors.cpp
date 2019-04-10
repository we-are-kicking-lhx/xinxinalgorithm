class Solution {
public:
    void f_swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size();
        int zero = 0, two = n - 1;
        for (int i = 0; i <= two; i++) {
            if (nums[i] == 0)f_swap(nums[zero++], nums[i]);
            else if(nums[i] == 2)f_swap(nums[two--], nums[i--]);
        }
        return;
    }
};