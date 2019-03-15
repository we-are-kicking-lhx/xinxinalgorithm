class Solution
{
  public:
    bool isValid(string S)
    {
        if (S.length() < 3)
            return false;
        vector<char> re;
        re.push_back(S[0]);
        re.push_back(S[1]);
        for (int i = 2; i < S.length(); i++)
        {
            if (re.size() < 2 || (re[re.size() - 1] != 'b' || re[re.size() - 2] != 'a' || S[i] != 'c'))
                re.push_back(S[i]);
            else
            {
                re.pop_back();
                re.pop_back();
            }
        }
        return re.empty();
    }
};