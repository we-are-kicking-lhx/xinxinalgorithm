#include <vector>
#include <string>
using namespace std;
class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> re;
        dfs(n, n, "", re);
        return re;
    }
    void dfs(int i, int j, string s, vector<string>& re)
    {
        if (j < i)
            return;
        if (i == 0 && j == 0)
            re.push_back(s);
        if (i > 0)
            dfs(i - 1, j, s + "(", re);
        if (j > 0)
            dfs(i, j - 1, s + ")", re);
    }
};