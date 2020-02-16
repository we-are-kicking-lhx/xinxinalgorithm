class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0},b[26]={0};
        int cnt = 0;
        for(auto c : ransomNote){
            a[c - 'a']++;
            cnt++;
        }
        for(auto c: magazine){
            if(a[c - 'a'] > 0){
                a[c - 'a']--;
                cnt--;
            }
            if(!cnt)
                return true;
        }
        if(!cnt)
            return true;
        return false;
    }
};