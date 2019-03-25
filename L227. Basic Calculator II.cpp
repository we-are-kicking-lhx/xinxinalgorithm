class Solution
{
  public:
    int calculate(string s)
    {
        stack<int> re;
        char op = '+';
        long long n = 0, result = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0';
            if ((s[i] < '0' && s[i] != ' ') || i == s.length() - 1)
            {
                if (op == '+')
                    re.push(n);
                if (op == '-')
                    re.push(-n);
                if (op == '/' || op == '*')
                {
                    int temp;
                    if (op == '/')
                        temp = re.top() / n;
                    if (op == '*')
                        temp = re.top() * n;
                    re.pop();
                    re.push(temp);
                }
                op = s[i];
                n = 0;
            }
        }
        while (!re.empty())
        {
            result += re.top();
            re.pop();
        }
        return result;
    }
};