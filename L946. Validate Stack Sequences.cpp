class Solution
{
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> re;
        int n = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            re.push(pushed[i]);
            while (!re.empty() && re.top() == popped[n])
            {
                re.pop();
                n++;
            }
        }
        return re.empty();
    }
};