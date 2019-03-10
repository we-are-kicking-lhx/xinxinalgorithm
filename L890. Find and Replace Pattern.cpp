class Solution
{
  public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> re;
        for (string i : words)
            if (equal(i, pattern))
                re.push_back(i);
        return re;
    }
    bool equal(string a, string b)
    {
        map<char, char> m1;
        map<char, char> m2;
        map<char, char>::iterator it1;
        map<char, char>::iterator it2;
        for (int i = 0; i < a.length(); i++)
        {
            it1 = m1.find(a[i]);
            if (it1 == m1.end())
                m1[a[i]] = b[i];
            else if (it1->second != b[i])
                return false;

            it2 = m2.find(b[i]);
            if (it2 == m2.end())
                m2[b[i]] = a[i];
            else if (it2->second != a[i])
                return false;
        }

        for (it1 = m1.begin(); it1 != m1.end(); it1++)
        {
            it2 = m2.find(it1->second);
            if (it2 == m2.end() || it2->second != it1->first)
                return false;
        }
        return true;
    }
};