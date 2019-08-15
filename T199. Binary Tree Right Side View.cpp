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
    int cnt = 0;
    vector<int>res;
    void dfs(TreeNode* root,int depth){
        if (cnt == depth){
            res.push_back(root->val);
            cnt++;
        }
        if (root->right != NULL)
            dfs(root->right, depth + 1);
        if (root->left != NULL)
            dfs(root->left, depth + 1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root != NULL)
            dfs(root, 0);
        return res;
    }
};