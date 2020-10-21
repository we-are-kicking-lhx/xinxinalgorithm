class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>res;
        for(int i = 0;i < queries.size();i++){
            string q = queries[i];
            int c1 = 0,c2 = 0;
            while(c1 < q.length()){
                if('Z' - q[c1] >= 0){
                    if(c2 >= pattern.length() || q[c1] != pattern[c2]){
                        res.emplace_back(false);
                        break;
                    }
                    c2++;
                }
                else{
                    if(q[c1] == pattern[c2])
                        c2++;
                }
                c1++;
            }
            if(res.size() < i + 1){
                if(c2 < pattern.length())
                    res.emplace_back(false);
                else
                    res.emplace_back(true);
            }
        }
        return res;
    }
};