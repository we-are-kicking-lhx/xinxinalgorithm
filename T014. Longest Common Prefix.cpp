class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(!size) return "";
        if(size == 1) return strs[0];
        int index = 0,flag = 0;
        while (1) {
            for (int i = 1; i < strs.size(); i++) {
                int len = strs[i].length();
                if (index == len)
                    flag = 1;
                if (!len ||strs[i][index] != strs[i - 1][index]){
                    flag = 2;
                    break;
                }
            }
            if (!flag || flag == 1)index++;
            if (flag) break;
        }
        return strs[0].substr(0,index);
    }
};