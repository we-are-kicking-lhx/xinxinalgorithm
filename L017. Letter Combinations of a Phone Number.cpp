class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
            return {};
        vector<string> re;

        dfs(re, digits, 0, "", dict);
        return re;
    }
    void dfs(vector<string> &re, string digits, int level, string s, string dict[])
    {
        if (level == digits.size())
        {
            re.push_back(s);
            return;
        }
        string str = dict[digits[level] - '0'];
        for (int i = 0; i < str.size(); i++)
            dfs(re, digits, level + 1, s + str[i], dict);
    }
};