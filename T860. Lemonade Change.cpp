class Solution {
public:
    int m[3]={0};
    int a[3] = {5,10,20};
    int greedy_search(int num){
        int i = 2;
        while(i >= 0){
            if(num < a[i] || !m[i]){
                i--;
                continue;
            }
            num -= a[i];
            m[i]--;
        }
        if(!num)return 1;
        return 0;
    }
    bool lemonadeChange(vector<int>& bills) {
        for(auto bill : bills){
            if(bill > 5){
                if(!greedy_search(bill - 5))
                    return false;
            }
            if(bill == 5)
                m[0]++;
            else if(bill == 10)
                m[1]++;
            else
                m[2]++;
        }
        return true;
    }
};