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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        node(root,x);
        int p=n-left-right-1;
        return max(p,max(left,right))>n/2;
    }
private:
    int left,right;
    int node(TreeNode* root,int x){
        if(!root) return 0;
        int l=node(root->left,x);
        int r=node(root->right,x);
        if(root->val==x){
            left=l;right=r;
        }
        return l+r+1;
    }
};