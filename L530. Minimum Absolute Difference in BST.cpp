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
    int minval=INT_MAX,pre=-1;
    int getMinimumDifference(TreeNode* root) {
        func(root,pre);
        return minval;
    }
    void func(TreeNode* root,int& pre){
        if(!root) return;
        func(root->left,pre);
        if(pre!=-1) minval=min(minval,root->val-pre);
        pre=root->val;
        func(root->right,pre);
    }
};