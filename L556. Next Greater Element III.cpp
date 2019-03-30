class Solution
{
  public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        int i = s.length() - 1;
        while (i > 0)
        {
            if (s[i] > s[i - 1])
                break;
            i--;
        }
        if (i == 0)
            return -1;
        for (int j = s.length() - 1; j >= i; j--)
        {
            if (s[j] > s[i - 1])
            {
                swap(s[j], s[i - 1]);
                break;
            }
        }
        sort(s.begin() + i, s.end());
        long long re = stoll(s);
        if (re > INT_MAX)
            return -1;
        else
            return re;
    }
};
