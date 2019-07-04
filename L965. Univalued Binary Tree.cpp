class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        return func(root,root->val);

    }
    bool func(TreeNode * node,int val){
        if(!node) return true;
        if(node->val!=val) return false;
        return func(node->left,val) && func(node->right,val); 
    }
};