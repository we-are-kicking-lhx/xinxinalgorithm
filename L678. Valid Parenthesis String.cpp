class Solution
{
  public:
    bool checkValidString(string s)
    {
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(' || s[i] == '*')
                l++;
            else
                l--;
            if (l < 0)
                return false;
        }
        if (!l)
            return true;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == ')' || s[i] == '*')
                r++;
            else
                --r;
            if (r < 0)
                return false;
        }
        return true;
    }
};