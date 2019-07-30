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
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        convertBST(root->right);
        root->val += sum;
        sum = root->val;
        convertBST(root->left);
        return root;
    }
};
// 前序遍历倒过来