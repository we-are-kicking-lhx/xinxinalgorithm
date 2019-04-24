
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> opera;
        int sum;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int one = opera.top();
                opera.pop();
                int two = opera.top();
                opera.pop();
                if (tokens[i] == "+")
                {
                    opera.push(one + two);
                }
                else if (tokens[i] == "-")
                {
                    opera.push(two - one);
                }
                else if (tokens[i] == "*")
                {
                    opera.push(one * two);
                }
                else if (tokens[i] == "/")
                {
                    opera.push(two / one);
                }
            }
            else
            {
                opera.push(atoi(tokens[i].c_str()));
            }
        }
        return opera.top();
    }
};
