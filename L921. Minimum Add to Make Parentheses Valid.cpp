class Solution
{
  public:
    int minAddToMakeValid(string S)
    {
        int n = 0, r = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
                r++;
            else
            {
                if (r != 0)
                    r--;
                else
                    n++;
            }
        }
        return n + r;
    }
};