class Solution
{
  public:
    bool backspaceCompare(string S, string T)
    {
        int topS = 0, topT = 0;
        for (int i = 0; i < S.length(); i++)
        {
            char c = S[i];
            if (c == '#')
            {
                if (topS > 0)
                    topS--;
            }
            else
                S[topS++] = c;
        }
        for (int i = 0; i < T.length(); i++)
        {
            char c = T[i];
            if (c == '#')
            {
                if (topT > 0)
                    topT--;
            }
            else
                T[topT++] = c;
        }

        if (topS != topT)
            return false;
        return S.substr(0, topS) == T.substr(0, topT);
    }
};