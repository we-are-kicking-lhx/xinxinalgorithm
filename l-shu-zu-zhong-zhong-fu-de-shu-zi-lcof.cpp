// class Solution {
// public:
//     int findRepeatNumber(vector<int>& nums) {
//         set<int> s;
//         for(int i=0;i<(int)nums.size();i++){
//             if(s.find(nums[i])==s.end()) s.insert(nums[i]);
//             else return nums[i] ;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0;i<(int)nums.size();++i){
            while(nums[i]!=i){
                if(nums[nums[i]]==nums[i]) return nums[i];
                swap(nums[nums[i]],nums[i]);
            }
        }
        return -1;
    }
};