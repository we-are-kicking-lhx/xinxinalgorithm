class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int i=0;
        while(candies){
            ans[i%num_people]+=min(i+1,candies);
            candies-=min(i+1,candies);
            i++;
        }
        return ans;
    }
};