class Solution
{
  public:
    string decodeString(string s)
    {
        string re = "", temp = "";
        stack<int> nums;
        stack<string> str;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                count = count * 10 + s[i] - '0';
            else if (s[i] == '[')
            {
                str.push(temp);
                nums.push(count);
                count = 0;
                temp = "";
            }
            else if (s[i] == ']')
            {
                int j = nums.top();
                nums.pop();
                for (int k = 0; k < j; k++)
                    str.top() = str.top() + temp;
                temp = str.top();
                str.pop();
            }
            else
                temp = temp + s[i];
        }
        if (str.empty())
            return temp;
        else
            return str.top();
    }
};