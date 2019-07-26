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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return {};
        auto t=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(t);;
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root) return {};
//         queue<TreeNode *> q{{root}};
//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 auto t=q.front();q.pop();
//                 auto t1=t->left;
//                 t->left=t->right;
//                 t->right=t1;
//                 if(t->left) q.push(t->left);
//                 if(t->right) q.push(t->right);
//             }    
//         }
//         return root;
//     }
// };
// 层序遍历