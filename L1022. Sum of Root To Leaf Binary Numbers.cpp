#include<bits/stdc++.h>
using namesapce std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return getSum(root,0);
    }
    int getSum(TreeNode* root,int s){
        if(root->left && root->right)
            return getSum(root->left,s*2+root->val)+getSum(root->right,s*2+root->val);
        else if(root->left)
            return getSum(root->left,s*2+root->val);
        else if(root->right)
            return getSum(root->right,s*2+root->val);
        else 
            return s*2+root->val;
    }
};