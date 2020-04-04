class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ld[26] = {0},ud[26] = {0};
        for (auto c : J) {
            int num = c - 'A';
            if (num >= 26)
                ld[c - 'a'] = 1;
            else
                ud[num] = 1;
        }
        int cnt = 0;
        for (auto c : S) {
            int num = c - 'A';
            if (num >= 26)
                cnt = ld[c - 'a'] ? cnt + 1 : cnt;
            else
                cnt = ud[num] ? cnt + 1 : cnt;
        }
        return cnt;
    }
};
//hashset
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int>hashmap;
        int cnt = 0;
        for(auto c : J)
            hashmap[c] = 1;
        for(auto c : S)
            if(hashmap[c] == 1)
                cnt++;
        return cnt;
    }
};