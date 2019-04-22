class Solution
{
  public:
    bool isValidSerialization(string preorder)
    {
        vector<string> ss = preprocess(preorder);
        if (ss.empty())
            return false;
        if (ss.size() == 1 && ss[0] == "#")
            return true;
        if (ss.size() > 1 && ss[0] == "#")
            return false;
        stack<bool> st;
        st.push(true);
        for (int i = 1; i < ss.size(); ++i)
        {
            if (st.empty())
                return false;
            bool top = st.top();
            st.pop();
            if (top)
            {
                st.push(false);
            }
            if (ss[i] != "#")
            {
                st.push(true);
            }
        }
        return st.empty();
    }

    vector<string> preprocess(string s)
    {
        int b = 0;
        vector<string> ret;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == ',')
            {
                ret.push_back(s.substr(b, i - b));
                b = i + 1;
            }
        }
        ret.push_back(s.substr(b, s.length() - b));
        return ret;
    }
};