class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>hashmap;
        vector<string>res;
        for(int i = 0;i < list1.size(); ++i){
            hashmap[list1[i]] = i;
        }
        int sum = 2002;
        for(int i = 0;i < list2.size(); ++i){
            if(hashmap.count(list2[i]) > 0){
                int num = hashmap[list2[i]] + i;
                if(num <= sum){
                    if(num < sum)res.clear();
                    sum = num;
                    res.push_back(list2[i]);
                }
            }
                
        }
        return res;
        
    }
};