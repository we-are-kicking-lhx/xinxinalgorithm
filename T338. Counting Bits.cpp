//最高有效位
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans = {0,1,1};
        int now = 2;
        for(int i = 3;i <= num; ++i){
            if(i == 2 * now){
                ans.emplace_back(1);
                now = i;
            }
            else
                ans.emplace_back(1 + ans[i - now]);
        }
        if(num < 2)ans.resize(num + 1);
        return ans;
    }
};

//最后设置位
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>ans = {0};
        for(int i = 1;i <= num; ++i){
            ans.emplace_back(ans[i&(i-1)] + 1);
        }
        return ans;
    }
};