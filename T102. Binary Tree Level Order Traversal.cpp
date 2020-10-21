class Solution {
public:
    vector<vector<int>>res;
    void helper(TreeNode* root,int level){
        if(res.size() == level)
            res.push_back({});
        res[level].push_back(root->val);
        if(root->left != NULL)
            helper(root->left, level + 1);
        if(root->right != NULL)
            helper(root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return res;
        helper(root, 0);
        return res;
    }
};