class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>hashmap_ab;
        for(auto i : A)
            for(auto j : B)
                hashmap_ab[i + j]++;
        int cnt = 0;
        for(auto i : C){
            for(auto j : D){
                if(hashmap_ab.count(0 - (i + j)) > 0)
                    cnt += hashmap_ab[0 - (i + j)];
            }
        }
        return cnt;
    }
};