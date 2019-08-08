#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         return func(root,root);
//     }
//     bool func(TreeNode* root1,TreeNode* root2){
//         if(!root1 && !root2) return true;
//         if(!root1 || !root2) return false;
//         return root1->val==root2->val && func(root1->right,root2->left) && func(root1->left,root2->left);
//     }
// };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            auto node1=q1.front();q1.pop();
            auto node2=q2.front();q2.pop();
            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val !=node2->val) return false;
            q1.push(node1->left);q1.push(node1->right);
            q2.push(node2->right);q2.push(node2->left);
        }
        return true;
    }
};
