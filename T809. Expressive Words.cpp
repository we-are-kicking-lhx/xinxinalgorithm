class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        if(!S.length())
            return 0;
        int cnt = 0;
        vector<pair<char,int>>alb;
        alb.push_back(make_pair(S[0],1));
        char last = S[0];
        for(int i = 1;i < S.length();i++){
            if(S[i]==last)
                alb.back().second++;
            else
                alb.push_back(make_pair(S[i],1));
            last = S[i];
        }
        for(string s : words){
            int curr = 0,i = 0,flag = 1;
            while(curr < alb.size() && i < s.length()){
                int s_cnt = 0;
                while(i < s.length() && s[i] == alb[curr].first){
                    s_cnt++;
                    i++;
                }
                if(s_cnt==0 || alb[curr].second < s_cnt ||alb[curr].second > s_cnt && alb[curr].second < 3){
                    flag = 0;
                    break;
                }
                curr++;
            }
            if(flag && curr == alb.size())cnt++;
        }
        return cnt;
    }
};