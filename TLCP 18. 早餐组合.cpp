class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        long long ans = 0;
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end(),greater<int>());
        int p1 = 0,p2 = 0,n1 = staple.size(),n2 = drinks.size();
        while(p1 < n1 && p2 < n2){
            if(staple[p1] + drinks[p2] <= x){
                p1++;
                ans += n2 - p2;
            }
            else
                p2++;
        }
        //binary search
        // int pos = 0;
        // for(int i = 0;i < drinks.size();i++){
        //     pos = upper_bound(staple.begin() + pos,staple.end(),x - drinks[i]) - staple.begin();
        //     ans += pos;

        // }
        return ans % 1000000007;
    }
};