class Solution
{
  public:
    bool checkPossibility(vector<int> &nums)
    {
        int n, count = 0;
        n = nums.size();
        for (int i = 1; i < n && count < 2; i++)
        {
            if (nums[i] >= nums[i - 1])
                continue;
            if (i - 2 >= 0 && nums[i] < nums[i - 2])
                nums[i] = nums[i - 1];
            else
                nums[i - 1] = nums[i];
            count++;
        }
        return count <= 1 ? true : false;
    }
};
