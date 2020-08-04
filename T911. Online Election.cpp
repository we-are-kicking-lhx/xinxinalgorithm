class TopVotedCandidate {
public:
    vector<int>top;
    vector<int>time;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        vector<int>votes(n,0);
        int max_num = 0;
        time = times;
        for(int i = 0;i < n; i++){
            // time.emplace_back(times[i]);
            votes[persons[i]]++;
            if(votes[persons[i]] >= max_num){
                max_num = votes[persons[i]];
                top.emplace_back(persons[i]);
            }
            else
                top.emplace_back(top.back());
        }
    }
    
    int q(int t) {
        int left = 0 , right = time.size();
        int pos = upper_bound(time.begin(),time.end(),t) - time.begin() - 1;
        return top[pos];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
