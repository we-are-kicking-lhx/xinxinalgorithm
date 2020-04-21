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
    int maxPathSum(TreeNode* root) {
        int cur=INT_MIN ;
        func(root,cur);
        return cur;
    }
    int func(TreeNode* root,int& cur){
        if(!root) return 0;
        int l=max(func(root->left,cur),0);
        int r=max(func(root->right,cur),0);
        cur=max(cur,l+r+root->val);
        return max(l,r)+root->val;
    }
};