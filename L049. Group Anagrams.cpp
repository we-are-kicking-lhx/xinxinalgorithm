class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> re;
        unordered_map<string, vector<string>> m;
        for (string str : strs)
        {
            string temp = "";
            vector<int> count(26, 0);

            for (char ch : str)
                ++count[ch - 'a'];
            for (int num : count)
                temp += to_string(num);
            m[temp].push_back(str);
        }
        for (auto a : m)
        {
            re.push_back(a.second);
        }
        return re;
    }
};

// 解法2：使用素数表示26个字母，将每个单词用一个数字表示