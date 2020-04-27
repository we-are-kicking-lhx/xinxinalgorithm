/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
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
//迭代
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL)
            return res;
        stack<TreeNode *>s;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            res.push_back(node->val);
            s.pop();
            if(node->left!=NULL)
                s.push(node->left);
            if(node->right!=NULL)
                s.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};