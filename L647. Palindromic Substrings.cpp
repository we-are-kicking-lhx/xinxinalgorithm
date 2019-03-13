class Solution
{
  public:
    int count = 0;

  public:
    int countSubstrings(string s)
    {
        if (s.length() == 0)
            return 0;
        string re = s.substr(0, 1);
        for (int i = 0; i < s.length(); i++)
        {
            string temp;
            temp = fun(i, i, s);
            if (temp.length() > re.length())
                re = temp;
            temp = fun(i, i + 1, s);
            if (temp.length() > re.length())
                re = temp;
        }
        return count;
    }
    string fun(int i, int j, string s)
    {
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            count++;
            i--;
            j++;
        }

        return s.substr(i + 1, j - i - 1);
    }
};