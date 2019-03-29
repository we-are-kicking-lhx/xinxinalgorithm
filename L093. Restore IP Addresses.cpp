class Solution
{
  public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> re;
        func(s, re, "", 0);
        return re;
    }
    void func(string s, vector<string> &re, string str, int count)
    {
        if (count == 4)
        {
            if (s.length() == 0)
                re.push_back(str);
        }

        else
        {
            for (int i = 1; i < 4; i++)
            {
                if (s.size() < i)
                    break;
                int temp = atoi(s.substr(0, i).c_str());
                if (temp > 255 || i != to_string(temp).size())
                    continue;
                func(s.substr(i), re, str + s.substr(0, i) + (count == 3 ? "" : "."), count + 1);
            }
        }
    }
};