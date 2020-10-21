//迭代
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        if(start == target)return true;
        vector<vector<int>>g(n+1);
        for(auto i : graph){
            g[i[0]].emplace_back(i[1]);
        }
        vector<int>visited(n,0);
        stack<int>s;
        s.push(start);
        visited[start] = 1;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(auto i : g[node]){
                if(i == target)
                    return true;
                if(!visited[i]){
                    s.push(i);
                    visited[i] = 1;
                }
            }
        }
        return false;
    }
};

//递归
class Solution {
public:
    vector<int>visited;
    vector<vector<int>>g;
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        g.resize(n);
        for(auto i : graph){
            g[i[0]].emplace_back(i[1]);
        }
        visited.resize(n,0);
        return dfs(start,target);
        
    }

    bool dfs(int start,int target){
        if(start == target)
            return true;
        visited[start] = true; 
        for(auto i : g[start]){
            if(!visited[i] && dfs(i,target))
                return true;
        }
        return false;
    }


};