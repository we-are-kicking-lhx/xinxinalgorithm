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
    int sum=0,LEFT=1,RIGHT=-1;
    int sumOfLeftLeaves(TreeNode* root) {
        func(root,0);
        return sum;
    }
    void func(TreeNode* root,int child){
        if(!root) return;
        func(root->left,LEFT);
        if(child==LEFT && !root->left && !root->right) sum+=root->val;
        func(root->right,RIGHT);
    }
};