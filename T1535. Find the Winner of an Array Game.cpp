class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(k >= n)
            return *max_element(arr.begin(),arr.end());
        int win = arr[0],cnt = 0;
        for(int i = 1;i < 2 * n; ++i){
            if(win > arr[i]){
                cnt++;
                arr.emplace_back(arr[i]);
            }
            else{
                win = arr[i];
                arr.emplace_back(win);
                cnt = 1;
            }
            if(cnt == k)return win;
        }
        return -1;
    }
};