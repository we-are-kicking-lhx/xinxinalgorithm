class Solution {
public:
    int n;
    vector<vector<int>>special;
    vector<int>price;
    int dfs(vector<int>&price,vector<vector<int>>&special,vector<int>needs){
        int cost = 0;
        for(int i = 0;i < n;i++)
            cost += price[i] * needs[i];
        for(auto s : special){
            int i = 0;
            vector<int>needs_t = needs;
            for(i = 0;i < n;i++){
                needs_t[i] -= s[i];
                if(needs_t[i] < 0)
                    break;
            }
            if(i == n)
                cost = min(cost,s[n] + dfs(price,special,needs_t));
        }
        return cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        return dfs(price,special,needs);
    }
};