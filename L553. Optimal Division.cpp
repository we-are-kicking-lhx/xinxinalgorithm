class Solution
{
  public:
    string optimalDivision(vector<int> &nums)
    {
        if (nums.size() == 1)
            return to_string(nums[0]);
        if (nums.size() == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        // 将第三个数及之后的数相乘，除第二个数
        string re = to_string(nums[1]);
        for (int i = 2; i < nums.size(); ++i)
        {
            re += "/";
            re += to_string(nums[i]);
        }
        return to_string(nums[0]) + "/" + "(" + re + ")";
    }
};