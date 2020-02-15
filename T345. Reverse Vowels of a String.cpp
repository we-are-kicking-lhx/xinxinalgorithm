class Solution {
public:
    bool is_vowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0,right = n - 1;
        while(left < right){
            if(!is_vowel(s[left])){
                left++;
                continue;
            }
            if(!is_vowel(s[right])){
                right--;
                continue;
            }
            char c = s[left];
            s[left] = s[right];
            s[right] = c;
            left++;
            right--;
        }
        return s;
    }
};