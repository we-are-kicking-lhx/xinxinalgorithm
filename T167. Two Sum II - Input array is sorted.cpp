class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int pos = upper_bound(numbers.begin(), numbers.end(),target) - numbers.begin();
        int p1 = 0;
        int p2 = min(pos,(int)numbers.size()-1);
        while (p1 < p2) {
            if(numbers[p1] + numbers[p2] < target)
                p1++;
            else if(numbers[p1] + numbers[p2] > target)
                p2--;
            else
                break;
        }
        return vector<int>{p1+1,p2+1};
    }
};