//栈
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char>s,t;
        for(char c : S){
            if(c == '#'){
                if(!s.empty())s.pop();
            }
            else
                s.push(c);
        }
        for(char c : T){
            if(c == '#'){
               if(!t.empty())t.pop();
            }
            else
                t.push(c);
        }
        while(!(s.empty()&&t.empty())){
            if(s.empty()||t.empty())
                return false;
            if(s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        return true;
    }
};
//双指针
//太麻烦了 思路简单 不写了