class Solution
{
  public:
    string reverseWords(string s)
    {
        istringstream is(s);
        string tmp;
        is >> s;
        while (is >> tmp)
            s = tmp + " " + s;
        if (!s.empty() && s[0] == ' ')
            s = "";
        return s;
    }
};