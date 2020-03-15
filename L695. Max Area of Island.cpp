class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
                ans=max(ans,dfs(grid,i,j));
        }
        return ans;

    }
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        int di[4]={0,1,0,-1};
        int dj[4]={1,0,-1,0};
        int ans=1;
        for(int k=0;k<4;k++){
            int next_i=i+di[k],next_j=j+dj[k];
            ans+=dfs(grid,next_i,next_j);
        }
        return ans;
    }
};