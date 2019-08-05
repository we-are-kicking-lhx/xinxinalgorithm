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
    int res;
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        postorder(root);
        return res;
    }
    int postorder(TreeNode* root){
        if(!root) return 0;
        int left=postorder(root->left);
        int right=postorder(root->right);
        res+=abs(left-right);
        return left+right+root->val;
    }
};