class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string temp = "";
        for (int i = 0; i < path.length(); i++) {
            if (path[i] != '/' ) {
                temp += path[i];
            }
            else{
                if (temp.length()) {
                    if (temp == ".."){
                        if (!s.empty())
                            s.pop();
                    }
                    else if (temp != ".")
                        s.push(temp);
                }
                temp = "";
            }
        }
        if (temp.length()) {
            if (temp == ".."){
                if (!s.empty())
                    s.pop();
            }
            else if (temp != ".")
                s.push(temp);
        }
        string ans = "";
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        ans = ans.length() ? ans : "/";
        return ans;
    }
};
//栈