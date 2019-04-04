class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        stack<int> s;
        vector<int> re(T.size());
        s.push(0);
        re[0] = 0;
        for (int i = 1; i < T.size(); i++)
        {
            while (T[i] > T[s.top()])
            {
                re[s.top()] = i - s.top();
                s.pop();
                if (s.size() == 0)
                    break;
            }
            s.push(i);
        }
        return re;
    }
};