class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        map<int,vector<int>>m;
        vector<int>res;
        for(auto i : nums)
            hashmap[i]++;
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i : hashmap)
            if(pq.size() == k){
                if(i.second > pq.top().first){
                    pq.pop();
                    pq.push(make_pair(i.second,i.first));
                }
            }
            else
                pq.push(make_pair(i.second,i.first));
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
//Hash + 堆排序 复杂度kO(logN) 需要注意求k最大需要的是小根堆(堆顶是根，比较需要比较是否比最小的小)
//但是 如果使用map<int,vector<int>>来对所有value，key进行一遍插入，是否也能得到相同的效果
//因为map是红黑树，插入O(logN)，综合下来应该也是满足题目要求的，但是我不会写这种情形的比较函数