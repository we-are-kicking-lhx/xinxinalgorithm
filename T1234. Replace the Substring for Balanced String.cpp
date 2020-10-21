class Solution {
public:
    bool isClear(map<char,int>&m,map<char,int>&need){
        for(auto i : m){
            if(i.second < need[i.first])
                return false;
        }
        return true;
    }

    int balancedString(string s) {
        map<char,int>need,m;
        int n = s.length();
        for(char c : s)
            need[c]++;
        for(auto &i : need){
            i.second = i.second - n / 4 > 0 ? i.second - n / 4 : 0;
            m[i.first] = 0;
        }
        if(isClear(m,need))return 0;
        int left = 0,right = 0,ans = 100000;
        while(right < s.length()){
            m[s[right]]++;

            while(isClear(m,need)){
                ans = min(ans,right - left + 1);
                m[s[left]]--;
                left++;
            }
            right++;
        }
        return ans;
    }
};
// 滑动窗口核心：右边界不过限，判断条件，左滑窗口如果满足条件就更新窗口长度，扩大右边界。