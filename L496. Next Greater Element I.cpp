class Solution
{
  public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        vector<int> re;
        stack<int> s;
        map<int, int> m;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i])
                s.pop();
            m[nums[i]] = s.empty() ? -1 : s.top();
            s.push(nums[i]);
        }
        for (int i = 0; i < findNums.size(); i++)
            re.push_back(m[findNums[i]]);
        return re;
    }
};