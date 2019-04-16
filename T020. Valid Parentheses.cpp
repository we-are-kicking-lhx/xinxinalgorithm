class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        map<char,char>m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '(' ||s[i] == '{'||s[i] == '[')
                p.push(s[i]);
            else{
                if (p.empty() || m[p.top()] != s[i])
                    return false;
                p.pop();
            }
        }
        if (!p.empty()) return false;
        return true;
    }
};