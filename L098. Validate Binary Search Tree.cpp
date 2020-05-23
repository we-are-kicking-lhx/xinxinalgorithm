class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
    bool helper(TreeNode* root, long min_val, long max_val)
    {
        if (!root)
            return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
    }
};