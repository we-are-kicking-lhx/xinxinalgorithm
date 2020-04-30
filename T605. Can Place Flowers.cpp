class Solution {
public:
    int max_flower(int x){
        if(x < 0)
            return 0;
        return (x+1)/2;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int last = -1;
        int ans = 0;
        int len = flowerbed.size();
        for(int i = 0;i < len;i++){
            if(flowerbed[i] == 1){
                if(last == -1)
                    ans += max_flower(i - 1 - 0);
                else
                    ans += max_flower((i - 1) - (last + 1) - 1);
                last = i;
                if(ans >= n)
                    return true;
            }
        }
        if(flowerbed[len - 1] == 1)
            if(last == -1) ans += max_flower(len - 1);
            else 
                ans += max_flower((len - 1 - 1) - (last + 1) - 1);
        else{
            if(last == -1) ans += max_flower(len);
            else
                ans += max_flower((len - 1) - (last + 1));
        }
        if(ans >= n)
            return true;
        return false;
    }
};