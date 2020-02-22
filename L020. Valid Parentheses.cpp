class Solution {
public:
    stack<char> st;
    bool isValid(string s) {
        for(auto ch : s){
            if(ch=='(' || ch=='{' ||  ch=='[') st.push(ch);
            else if(ch==')'){
                if(!st.empty() && st.top()=='(') st.pop();
                else return false;
            } else if(ch=='}'){
                if(!st.empty() && st.top()=='{') st.pop();
                else return false;
            } else if(ch==']'){
                if(!st.empty() && st.top()=='[') st.pop();
                else return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};