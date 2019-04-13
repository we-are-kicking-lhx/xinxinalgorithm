class Solution
{
  public:
    string removeKdigits(string num, int k)
    {
        int len = num.length(), n = k, count = 0;
        string s;
        for (auto ch : num)
        {
            while (!s.empty() && n > 0 && ch < s.back())
            {
                n--;
                s.pop_back();
            }
            s.push_back(ch);
        }
        while (s[count] == '0')
            count++;
        s = s.substr(count, len - k - count);
        return !s.length() ? "0" : s;
    }
};