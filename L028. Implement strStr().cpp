#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int i=0,j=0;
        int len1=haystack.length(),len2=needle.length();
        vector<int> next=getnext(needle);
        while((i<len1) && (j<len2)){
            if((j==-1)||(haystack[i]==needle[j])){
                i++;j++;
            }else
            {
                j=next[j];
            }
            
        }
        if(j==len2) return i-j;
        return -1;
    }
    vector<int> getnext(string str){
        int len=str.length();
        vector<int> next(len);
        next[0]=-1;
        int i=0,j=-1;
        while(i<len-1){
            if(j==-1 || str[i]==str[j]){
                i++;j++;
                next[i]=j;
            }else
            {
                j=next[j];
            }
            
        }
        return next;
    }
};
