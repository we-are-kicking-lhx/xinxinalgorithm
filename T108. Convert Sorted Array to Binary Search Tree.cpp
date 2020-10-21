class Solution {
public:
    vector<int>nodes;
    TreeNode* res= new TreeNode(0);

    TreeNode* make_tree(int s, int e){
        if(s <= e){
            TreeNode* tree = new TreeNode(nodes[(s+e)/2]);
            tree->left = make_tree(s,(s+e)/2 - 1);
            tree->right = make_tree((s+e)/2 + 1,e);
            return tree;
        }
        else
            return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(!n)return NULL;
        nodes = nums;
        return make_tree(0,n-1);
    }
};