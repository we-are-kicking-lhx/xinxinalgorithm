// #include<bits/stdc++.h>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    int level=0;
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return level;
    }
    void dfs(TreeNode* node,int l){
        if(l>level) level=l;
        if(!node) return;
        dfs(node->left,l+1);
        dfs(node->right,l+1);
    }
};