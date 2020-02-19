class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        if(!s.length())
            return 0;
        int last = s[0] == ' ' ? 1 : 0;
        for(auto c : s){
            if(c == ' '){
                if(!last)
                    cnt++;
                last = 1;
            }
            else
                last = 0;
        }
        if(s[s.length() - 1] == ' ')
            return cnt;
        return cnt + 1;
    }
};