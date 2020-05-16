class Solution {
public:
    bool canPermutePalindrome(string s) {
        int len = s.length();
        unordered_map<char,int>alphabet;
        for(char c : s){
            alphabet[c]++;
        }
        int odd_num = 0;
        for(auto i : alphabet){
            if(i.second % 2){
                odd_num++;
                if(odd_num > 1 || len % 2 == 0)
                    return false;
            }
        }
        return true;
    }
};