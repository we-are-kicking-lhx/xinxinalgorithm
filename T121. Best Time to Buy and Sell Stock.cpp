class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 32767,res = 0;
        for(auto i : prices){
            if(i < low)low = i;
            else if(i > low)
                res = res > i - low ? res: i - low;
        }
        return res;
    }
};
21. Best Time to Buy and Sell Stock