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

    int findTilt(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        return abs(findTilt(root->left)-findTilt(root->right)); 
    }
};