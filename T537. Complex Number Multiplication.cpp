class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,b1,a2,b2;
        
        int pos = a.find('+');
        a1 = stoi(a.substr(0, pos));
        b1 = stoi(a.substr(pos + 1, a.length() - pos - 1));
        
        pos = b.find('+');
        a2 = stoi(b.substr(0, pos));
        b2 = stoi(b.substr(pos + 1, b.length() - pos - 2));
        
        return to_string(a1 * a2 - b1 * b2) + "+" + to_string(a1 * b2 + a2 * b1) + "i";
    }
};