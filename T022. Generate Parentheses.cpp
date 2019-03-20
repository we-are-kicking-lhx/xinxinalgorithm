class Solution {
    vector<string>res;
    int n;
public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        fun(0, 0, "");
        return res;
    }
    
    void fun(int left,int right,string s){
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }
        
        if (left < n) {
            fun(left + 1, right, s + "(");
        }
        
        if (right < n && right < left) {
            fun(left, right + 1, s + ")");
        }
    }
};
