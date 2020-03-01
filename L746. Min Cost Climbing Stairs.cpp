// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int> dp(cost.size());
//         dp[0]=cost[0];dp[1]=cost[1];
//         for(int i=2;i<cost.size();i++){
//             dp[i]=min(dp[i-1],dp[i-2])+cost[i];
//         }
//         return min(dp[cost.size()-1],dp[cost.size()-2]);
//     }
// };
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=cost[0],b=cost[1];
        for(int i=2;i<cost.size();i++){
            int temp=b;
            b=min(a,b)+cost[i];
            a=temp;;
        }
        return min(a,b);
    }
};