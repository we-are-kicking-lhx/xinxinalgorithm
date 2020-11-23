int cmp(vector<int>x,vector<int>y){
    if(x[0] != y[0])
        return x[0] < y[0];
    return x[1] < y[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0)return 0;
        sort(points.begin(),points.end(),cmp);
        int area[2],cnt = 1;
        area[0] = points[0][0];
        area[1] = points[0][1];
        for(int i = 1;i < points.size(); ++i){
            if(points[i][0] <= area[1]){
                area[0] = points[i][0];
                area[1] = min(points[i][1],area[1]);
            }
            else{
                cnt++;
                area[0] = points[i][0];
                area[1] = points[i][1];
            }
        }
        return cnt;
    }
};