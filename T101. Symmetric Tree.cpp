class Solution {
public:
    bool isSymmetric0(TreeNode* l,TreeNode* r){
        if(l == NULL && r == NULL)
            return true;
        if(l !=NULL && r !=NULL)
            return l->val == r->val && isSymmetric0(l->left,r->right) && isSymmetric0(l->right,r->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) 
            return true;
        return isSymmetric0(root->left,root->right);
    }
};