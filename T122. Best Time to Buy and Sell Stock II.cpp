class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int last = 32767,res = 0;
        for(auto i : prices){
            if (i > last)
                res += i - last;
            last = i;
        }
        return res;
    }
};