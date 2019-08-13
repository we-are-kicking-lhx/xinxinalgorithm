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
    int min1=-1,min2=-1;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        min1=root->val;
        func(root->left);
        func(root->right);
        return min2;
    }
    void func(TreeNode* root){
        if(!root) return;
        if(min2==-1 && root->val>min1) min2=root->val;
        else if(min2!=-1 && root->val<min2 && root->val>min1) min2=root->val;
        func(root->left);
        func(root->right);
    }
};