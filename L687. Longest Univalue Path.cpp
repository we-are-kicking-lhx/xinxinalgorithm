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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        func(root,ans);
        return ans;
    }

    int func(TreeNode* root,int& ans){
        if(!root) return 0;
        int l=func(root->left,ans);
        int r=func(root->right,ans);
        int pl=0,pr=0;
        if(root->left && root->val==root->left->val) pl=l+1;
        if(root->right && root->val==root->right->val) pr=r+1;
        ans=max(ans,pl+pr);
        return max(pr,pl);
    }
};