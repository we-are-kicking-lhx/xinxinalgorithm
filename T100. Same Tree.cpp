class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p != NULL && q != NULL)
            return isSameTree(p->left,q->left) && p->val == q->val && isSameTree(p->right,q->right);
        return false;
    }
};