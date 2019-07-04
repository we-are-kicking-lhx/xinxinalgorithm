class Solution {
public:
    int res=1;
    int maxDepth(Node* root) {
        if(!root) return 0;
        func(root,1);
        return  res;
    }
    void func(Node* root,int level){
        if(level>res) res=level;
        if(root->children.size()==0) return ;
        for(Node* node:root->children){
            dfs(node,level+1);
        }
    }
};