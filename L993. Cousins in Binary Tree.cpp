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
    int xd,yd;
    TreeNode* xr;
    TreeNode* yr;
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        xd=-1;yd=-2;
        xv=x;yv=y;
        xr=nullptr;yr=nullptr;
        func(root,0,nullptr);
        return xd==yd && xr!=yr;
    }
    void func(TreeNode* root,int depth,,TreeNode* p){
        if(!root) return;
        if(root->val==xv) {xd=depth;xr=p;}
        if(root->val==yv) {yd=depth;yr=p;}
        func(root->left,depth+1,root);
        func(root->right,depth+1,root);
    }
};