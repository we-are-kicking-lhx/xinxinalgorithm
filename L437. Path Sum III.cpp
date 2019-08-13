#include<bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sum_up(0,root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int sum_up(int pre,TreeNode* root,int sum){
        if(!root) return 0;
        int cur=root->val+pre;
        return (pre==sum)+sum_up(cur,root->left,sum)+sum_up(cur,root->right,sum);
    }
};