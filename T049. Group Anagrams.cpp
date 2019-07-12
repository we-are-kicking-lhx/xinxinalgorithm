class Solution {
public:
    string dict(string s){
        int r[26] = {0};
        for(int i = 0;i < s.length();i++){
            r[s[i] - 'a'] += 1;
        }
        string res = "";
        for(int i = 0;i < 26;i++){
            res += to_string(r[i]);
        }
        return res;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string>dicts;
        vector<string>::iterator it;
        for (it = strs.begin(); it != strs.end(); it++) {
            string vec = dict(*it);
            int flag = -1;
            for(int i = 0;i < dicts.size();i++){
                if (dicts[i] == vec){
                    flag = i;
                    break;
                }
            }
            if(flag == -1){
                dicts.push_back(vec);
                vector<string> new_vec;
                new_vec.push_back(*it);
                res.push_back(new_vec);
            }
            else res[flag].push_back(*it);
        }
        return res;
    }
};