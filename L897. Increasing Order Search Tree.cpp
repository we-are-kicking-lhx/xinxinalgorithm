class Solution {
public:
    TreeNode* cur;  
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* res=new TreeNode(0);
        cur=res;
        func(root);
        return res->right;
    }
    void func(TreeNode* node){
        if(!node) return;
        func(node->left);
        cur->left=nullptr;
        cur->right=node;
        cur=cur->right;
        func(node->right);
    }

};