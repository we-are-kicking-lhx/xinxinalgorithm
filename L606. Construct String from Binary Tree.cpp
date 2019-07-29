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
    string tree2str(TreeNode* t) {
        if(!t) return "";
        return preorder(t);
    }
    string preorder(TreeNode* root){
        if(root->left && root->right) return to_string(root->val)+"("+preorder(root->left)+")"+"("+preorder(root->right)+")";
        else if(root->right) return to_string(root->val)+"()("+preorder(root->right)+")";
        else if(root->left) return to_string(root->val)+"("+preorder(root->left)+")";
        else return to_string(root->val);
    }
};