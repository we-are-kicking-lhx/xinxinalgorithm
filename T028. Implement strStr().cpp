class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length(),n2 = needle.length();
        if(!n2)return 0;
        if(!n1)return -1;
        int p = 0;
        while(p < n1 - n2 + 1){
            if(haystack[p] == needle[0]){
                int len = n2 - 1;
                int flag = 1;
                for(int i = 1;i < n2;i++){
                    if(needle[i] != haystack[p+i]){
                        flag = 0;
                        break;
                    }
                }
                if(flag) return p;
            }
            p++;
        }
        return -1;
    }
};