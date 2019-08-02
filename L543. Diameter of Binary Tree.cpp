#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int res=0;
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return res;
    }
    int depth(TreeNode * root){
        if(!root) return 0;
        int left=depth(root->left);
        int right=depth(root->right);
        res=max(res,left+right);
        return max(left,right)+1;
    }
};