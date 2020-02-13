class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int s,e,ans=nums[0]+nums[1]+nums[nums.size()-1];
        for(int i=0;i<nums.size()-2;i++){
            s=i+1;e=nums.size()-1;
            while(s<e){
                int sum=nums[i]+nums[e]+nums[s];
                if(abs(target-sum)<abs(target-ans))
                    ans=sum;
                if(sum>target)
                    e--;
                else if(sum<target)
                    s++;
                else
                    return ans;
            }
        }
        return ans;
    }
};