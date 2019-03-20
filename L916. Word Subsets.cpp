class Solution
{
  public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        int allb[26], b[26], a[26];
        memset(allb, 0, sizeof(allb));
        for (string bs : B)
        {
            memset(b, 0, sizeof(b));
            for (char ch : bs)
                b[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                allb[i] = max(allb[i], b[i]);
        }

        vector<string> ans;
        for (string as : A)
        {
            memset(a, 0, sizeof(a));
            for (char ch : as)
                a[ch - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++)
                if (a[i] < allb[i])
                {
                    ok = false;
                    break;
                }
            if (ok)
                ans.push_back(as);
        }
        return ans;
    }
};