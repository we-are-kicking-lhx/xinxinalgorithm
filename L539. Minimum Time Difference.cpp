class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int min_num = INT_MAX ;
        vector<int> nums;
        for (string s : timePoints) {
            int h = stoi(s.substr(0, 2)), m = stoi(s.substr(3));
            nums.push_back(h * 60 + m);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < timePoints.size(); ++i) {
            min_num = min(min_num, nums[i] - nums[i - 1]);
        }
        return min(min_num, 1440 + nums[0] - nums.back());
    }
};