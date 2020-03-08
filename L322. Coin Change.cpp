class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=INT_MAX;
        sort(coins.rbegin(),coins.rend());
        func(coins,amount,0,ans,0);
        return ans==INT_MAX?-1:ans;
    }
    void func(vector<int>& coins,int amount,int index,int& ans,int count){
        if(amount==0){
            ans=min(count,ans);
            return;
        } 
        if(index==coins.size()) return;
        for(int i=amount/coins[index];i>=0 && i+count<ans;i--){
            func(coins,amount-i*coins[index],index+1,ans,count+i);
        }
    }
};