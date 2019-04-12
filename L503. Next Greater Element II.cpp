#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> re(nums.size(), -1);
        stack<int> s;
        for (int i = 0; i < 2 * nums.size(); i++)
        {
            int num = nums[i % nums.size()];
            while (!s.empty() && nums[s.top()] < num)
            {
                re[s.top()] = num;
                s.pop();
            }
            if (i < nums.size())
                s.push(i);
        }
        return re;
    }
};

// class Solution
// {
//   public:
//     vector<int> nextGreaterElements(vector<int> &nums)
//     {
//         vector<int> re(nums.size(), -1);
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int j = (i + 1) % nums.size();
//             while (j != i && nums[j] <= nums[i])
//                 j = (j + 1) % nums.size();
//             if (j != i)
//                 re[i] = nums[j];
//         }
//         return re;
//     }
// };