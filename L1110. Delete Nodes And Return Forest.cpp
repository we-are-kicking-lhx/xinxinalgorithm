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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> del(to_delete.begin(),to_delete.end());
        vector<TreeNode*>ans;
        root=process(root,ans,del);
        if(root) ans.push_back(root);
        return ans;
    }
private:
    TreeNode* process(TreeNode* root,vector<TreeNode*>& ans,set<int> del){
        if(!root) return nullptr;
        root->left=process(root->left,ans,del);
        root->right=process(root->right,ans,del);
        if(del.count(root->val)==0) return root;
        if(root->left) ans.push_back(root->left);
        if(root->right) ans.push_back(root->right);
        return nullptr;
    }
};