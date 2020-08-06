class Solution {
public:
    int search(vector<int>& arr, int target) {
        int first = arr[0],cnt = arr.size() - 1;
        while(cnt >= 0 && arr[cnt]==first){
            cnt--;
        }
        int index = findIndex(arr,cnt);
        int left = 0,right = cnt;
        cnt = cnt < 0 ? arr.size() - 1 : cnt;
        if(target > arr[cnt])
            right = index - 1;
        else
            left = index;
        return bs(arr,left,right,target);

    }
    int bs(vector<int>& arr,int left,int right,int target){
        while(left < right){
            int mid = left + (right - left)/2;
            if(arr[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        if(arr[left] == target)
            return left;
        else
            return -1;
    }
    int findIndex(vector<int>& arr,int n){
        int left = 0,right = n;
        while(left < right){
            int mid = left + (right - left)/2;
            if(arr[mid] <= arr[right])
                right = mid;
            else
                left = mid + 1;   
        }
        return left;
    }
};