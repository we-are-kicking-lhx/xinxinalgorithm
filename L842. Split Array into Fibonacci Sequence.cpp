class Solution
{
  public:
    vector<int> splitIntoFibonacci(string S)
    {
        vector<int> re;
        dfs(re, S, 0);
        return re;
    }
    bool dfs(vector<int> &re, string s, int i)
    {
        if (re.size() >= 3 && i >= s.length())
            return true;
        for (int j = 1; j + i <= s.length(); ++j)
        {
            if (j > 1 && s[i] == '0')
                break;
            long long temp = stoll(s.substr(i, j));
            if (temp > INT_MAX)
                return false;
            if (re.size() >= 2 && (temp > (long long)re[re.size() - 1] + (long long)re[re.size() - 2]))
                return false;
            if (re.size() <= 1 || temp == (long long)re[re.size() - 1] + (long long)re[re.size() - 2])
            {
                re.push_back((int)temp);
                if (dfs(re, s, i + j))
                    return true;
                re.pop_back();
            }
        }
        return false;
    }
};