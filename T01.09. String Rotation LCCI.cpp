class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        return s1.length()==s2.length()&&(s1 + s1).find(s2) != -1;
    }
};