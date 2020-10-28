class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>hashmap;
        for(auto i : arr)
            hashmap[i]++;
        unordered_set<int>hashset;
        for(auto i : hashmap)
            hashset.insert(i.second);
        if(hashmap.size()==hashset.size())
            return true;
        return false;
    }
};