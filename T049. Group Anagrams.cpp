class Solution {
public:
    string getSeq(string s){
        int dict[26] = {};
        for(auto c : s)
            dict[c - 'a']++;
        s = " ";
        for(auto i : dict){
            s += to_string(i);
            s += "#";
        }
        return s;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>hashmap;
        vector<vector<string>>ans;
        int cnt = 0;
        for(auto s : strs){
            string seq = getSeq(s);
            if(hashmap.count(seq) == 0){
                ans.push_back(vector<string>());
                hashmap[seq] = cnt++;
                ans[cnt - 1].push_back(s);
            }
            else 
                ans[hashmap[seq]].push_back(s);
        }
        return ans;
    }
};
//转换为数字序列再hash