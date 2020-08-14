class MapSum {
private:
    MapSum *next[26];
    int val;
public:
    MapSum() {
        this->val = 0;
        memset(next,0,sizeof(next));
    }
    
    void insert(string key, int val) {
        MapSum *node = this;
        for(auto c : key){
            if(!node->next[c-'a']) 
               node->next[c-'a'] = new MapSum();
            node = node->next[c-'a'];
        }
        node->val = val;
    }
    
    int backtrack(MapSum *node){
        int sum = node->val;
        for(auto it : node->next){
            if(it != NULL)sum += backtrack(it);
            
        }
        return sum;
    }

    int sum(string prefix) {
        // cout << prefix << endl;
        MapSum *node = this;
        for(char c : prefix){
            if(!node->next[c-'a']) 
               return 0;
            node = node->next[c-'a'];
        }       
        return backtrack(node);
    }
};