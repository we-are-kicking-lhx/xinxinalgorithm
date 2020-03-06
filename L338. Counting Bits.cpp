class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1);
        for(int i=1;i<=num;i++){
            ans[i]=ans[i>>1]+(i&1);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans(num+1);
//         int i=0,j=1;
//         while(j<=num){
//             while(i<j && i+j<=num ){
//                 ans[i+j]=ans[i]+1;
//                 i++;
//             }
//             i=0;
//             j<<=1;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> countBits(int num) {
//         vector<int> ans;
//         for(int i=0;i<=num;i++)
//             ans.emplace_back(func(i));
//         return ans;
//     }
//     int func(int n){
//         int sum=0;
//         while(n){
//             sum++;
//             n&=(n-1);
//         }
//         return sum;
//     }
// };