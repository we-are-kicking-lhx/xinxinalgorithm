class Solution
{
  public:
    string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
    {
        vector<pair<int, int>> p;
        for (int i = 0; i < indexes.size(); i++)
            p.push_back(make_pair(indexes[i], i));
        sort(p.rbegin(), p.rend());
        for (int i = 0; i < indexes.size(); i++)
        {
            if (S.find(sources[p[i].second], p[i].first) == p[i].first)
                S = S.substr(0, p[i].first) + targets[p[i].second] + S.substr(p[i].first + sources[p[i].second].length());
        }
        return S;
    }
};
