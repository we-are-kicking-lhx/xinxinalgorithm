class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};