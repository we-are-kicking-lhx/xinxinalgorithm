class Solution
{
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {

        stack<int> s;
        vector<int> re(n, 0);
        int pre = 0;
        for (string log : logs)
        {
            int pos1 = log.find(":");
            int pos2 = log.find_last_of(":");
            int id = stoi(log.substr(0, pos1));
            string temp = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int t = stoi(log.substr(pos2 + 1));
            if (!s.empty())
                re[s.top()] += t - pre;
            pre = t;
            if (temp == "start")
                s.push(id);
            else
            {
                re[s.top()]++;
                pre++;
                s.pop();
            }
        }
        return re;
    }
};