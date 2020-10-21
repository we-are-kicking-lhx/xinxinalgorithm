class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char>s1 = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0,right = s.length() - 1;
        while(left < right){
            if(s1.count(s[left]) == 0){
                left++;
                continue;
            }
            if(s1.count(s[right]) == 0){
                right--;
                continue;
            }
            swap(s[left++],s[right--]);
        }
        return s;
    }
};