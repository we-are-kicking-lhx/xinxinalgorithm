class Solution
{
  public:
    int scoreOfParentheses(string S)
    {
        stack<string> re;
        int num = 0;
        for (int i = 0; i < S.length(); i++)
            if (S[i] == '(')
                re.push("(");
            else
            {
                if (re.top() == "(")
                {
                    re.pop();
                    re.push("1");
                }
                else
                {
                    int temp = 0;
                    while (re.top() != "(")
                    {
                        temp += stoi(re.top());
                        re.pop();
                    }
                    re.pop();
                    re.push(to_string(2 * temp));
                }
            }
        while (!re.empty())
        {
            num += stoi(re.top());
            re.pop();
        }
        return num;
    }
};