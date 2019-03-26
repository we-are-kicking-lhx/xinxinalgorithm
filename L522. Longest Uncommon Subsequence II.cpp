class Solution
{
  public:
    int findLUSlength(vector<string> &strs)
    {
        int re = -1;
        for (int i = 0; i < strs.size(); i++)
        {
            bool flag = true;
            for (int j = 0; j < strs.size(); j++)
            {
                if (i != j && func(strs[i], strs[j]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                re = max(re, (int)strs[i].size());
        }
        return re;
    }
    bool func(string a, string b)
    {
        int count = 0;
        for (int i = 0; i < b.length(); i++)
        {
            if (b[i] == a[count])
                count++;
            if (count == a.length())
                break;
        }
        return count == a.length();
    }
};