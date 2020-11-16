int cmp(vector<int>x,vector<int>y){
    if(x[0] != y[0])
        return x[0] > y[0];
    else
        return x[1] < y[1];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>>ans;
        for(auto i : people){
            ans.insert(ans.begin()+i[1],i);
        }
        return ans;
    }
};