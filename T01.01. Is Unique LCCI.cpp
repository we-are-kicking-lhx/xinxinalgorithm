class Solution {
public:
    bool isUnique(string astr) {
        int alphabet = 0;
        for(char c : astr){
            if(alphabet & (1 << (c - 'a')))
                return false;
            else
                alphabet |= 1 << (c - 'a');
        }
        return true;
    }
};