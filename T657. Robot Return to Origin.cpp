class Solution {
public:
    bool judgeCircle(string moves) {
        int u = 0,d = 0,l = 0,r = 0;
        for(auto c : moves){
            if (c == 'U')
                u++;
            else if(c == 'D')
                d++;
            else if (c == 'L')
                l++;
            else
                r++;
        }
        if (u == d && l == r)
            return true;
        return false;
    }
};