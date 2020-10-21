class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>hashmap;
        for(char c : magazine)
            hashmap[c]++;
        for(char c : ransomNote){
            if(hashmap.count(c) == 0 || hashmap[c] == 0)
                return false;
            else
                hashmap[c]--;
        }
        return true;
    }
};