class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> re;
        int i=1,j=2;
        while(i<j){
            int sum=(i+j)*(j-i+1)/2;
            if(sum<target) j++;
            else if(sum>target) i++; 
            else{
                re.clear();
                for(int k=i;k<=j;k++)
                    re.emplace_back(k);
                ans.emplace_back(re);
                i++;
            }
        }
        return ans;
    }
};