/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* node){
        if(node == NULL)
            return;
        if(node->left != NULL)
            dfs(node->left);
        if(node->right != NULL)
            dfs(node->right);
        res.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};