class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string ans=to_string(1);
        for(int i=0;i<n-1;i++)
            ans=func(ans);
        return ans;
    }
    string func(string str){
        int i=0;
        string ans="";
        char ch=str[0];
        for(char c:str){
            if(c==ch)i++;
            else{
                ans+=to_string(i)+ch;
                ch=c;i=1;
            }
        }
        ans+=to_string(i)+ch;
        return ans;
    }
};