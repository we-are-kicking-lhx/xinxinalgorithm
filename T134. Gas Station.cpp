class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int lowest = 32467;
        int lowest_index = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++){
           total += (gas[i] - cost[i]);
           if(total < lowest){
               lowest_index = i;
               lowest = total;
           }
        }
        if(total < 0)
            return -1;
        else
            return (lowest_index + 1)%n;
    }
};
//这题很奇妙，利用一个折线图，计算最低的累计和
//首先应该思考何时会无解：最终累计和小于0
//其次就可以用贪心的思路思考，从i点出发 == 最后才用考虑i-1到i的cost，所以选择累计和最小的站开始