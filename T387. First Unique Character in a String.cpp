class Solution {
public:
    int firstUniqChar(string s) {
        int a[26];
        for(int i = 0;i < 26;i++)
            a[i] = -1;
        vector<int>d = vector<int>(s.length(),0);
        for(int i = 0;i < s.length(); i++){
            if(a[s[i] - 'a'] == -1){
                a[s[i] - 'a'] = i;
            }
            d[a[s[i] - 'a']]++;
        }
        for(int i = 0;i < s.length();i++){
            if(d[i] == 1)
                return i;
        }
        return -1;
    }
};