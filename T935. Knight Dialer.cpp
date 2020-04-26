class Solution {
public:
    int knightDialer(int N) {
        vector<long long>state({1,1,1,1});
        if(N == 1)return 10;
        while(--N){
            state = {2*state[1]+state[3],state[0]+state[2],2 * state[1], 2 * state[0]};
            for(auto &i : state)
                i = i % 1000000007;
        }
        return (2 * state[0]+4*state[1]+2*state[2]+state[3]) % 1000000007;
    }
};
//利用了状态机
//取余加和 值不受影响