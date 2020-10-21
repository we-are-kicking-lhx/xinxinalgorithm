class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int no[1001] = {};
        for(auto i : trust){
            no[i[0]] = -1;
            if(no[i[1]] != -1)no[i[1]]++;
        }
        no[0] = -1;
        for(int i = 1;i <= N; i++){
            if(no[i] == N - 1)
                return i;
        }
        return -1;
    }
};
997. 找到小镇的法官
