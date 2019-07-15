class Solution {
public:
    bool static cmp(string s1,string s2){
        string a = s1 + s2;
        string b = s2 + s1;
        return a > b;
    }
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string>s_nums;
        for (int i = 0; i < n; i++) {
            s_nums.push_back(to_string(nums[i]));
        }
        sort(s_nums.begin(), s_nums.end(), cmp);
        if(s_nums[0] == "0")
            return "0";
        string res = "";
        for (int i = 0; i < n; i++) {
            res += s_nums[i];
        }
        return res;
    }
};