class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>out_d(n,0);
        for(auto e : edges){
            out_d[e[1]]++;
        }
        vector<int>ans;
        for(int i = 0;i < n; ++i){
            if(out_d[i] == 0)ans.emplace_back(i);
        }
        return ans;
    }
};