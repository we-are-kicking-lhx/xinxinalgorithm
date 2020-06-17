class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int mx = A[0],ans = 0;
        for(int i = 1;i < A.size();i++){
        	int score = mx + A[i] - i;
        	if(ans < score)
                ans = score;
        	if(mx < A[i] + i)
                mx = A[i] + i;
        }
        return ans;
    }
};