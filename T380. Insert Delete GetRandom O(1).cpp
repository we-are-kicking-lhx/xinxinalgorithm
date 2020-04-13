class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int>hashmap;
    vector<int>nums;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashmap.count(val) == 0){
            hashmap[val] = nums.size();
            nums.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {

        if(hashmap.count(val) > 0){
            int index = hashmap[val];
            int last =*(nums.end() - 1);
            nums[index] = last;
            nums.pop_back();
            hashmap[last] = index;
            hashmap.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int len = hashmap.size();
        int i = rand() % len;
        return nums[i];
    }
};