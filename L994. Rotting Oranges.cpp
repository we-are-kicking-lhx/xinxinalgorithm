class Solution {
public:
    int cnt=0,ans=0;
    int dis[10][10];
    int grid_x[4]={0,1,0,-1};
    int grid_y[4]={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>Q;
        memset(dis,0,sizeof(dis));
        int m=(int)grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    Q.push(make_pair(i,j));
                    dis[i][j]=0;
                }
                if(grid[i][j]==1)
                    cnt++;
            }
        }
        while(!Q.empty()){
            auto temp=Q.front();Q.pop();
            for(int i=0;i<4;i++){
                int x=temp.first+grid_x[i];
                int y=temp.second+grid_y[i];
                if((x<m && x>=0) && (y<n && y>=0) && (grid[x][y]==1)){
                    dis[x][y]=dis[temp.first][temp.second]+1;
                    Q.push(make_pair(x,y));
                    if(grid[x][y]==1){
                        cnt--;
                        ans=dis[x][y];
                        grid[x][y]=2;
                        if(!cnt) break;
                    }
                }

            }
        }
        return cnt?-1:ans;
    }
};