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
    vector<string>res;
    void dfs(TreeNode* t,string str){
        str += to_string(t ->val);
        if (t->left == NULL && t->right == NULL) {
            res.push_back(str);
            return;
        }
        str += "->";
        if (t -> left != NULL)
            dfs(t->left,str);
        if (t -> right != NULL)
            dfs(t->right,str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return res;
        dfs(root, "");
        return res;
    }
};