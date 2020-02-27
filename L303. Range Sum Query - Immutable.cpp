class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        sum.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++)
            sum[i+1]=sum[i]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

