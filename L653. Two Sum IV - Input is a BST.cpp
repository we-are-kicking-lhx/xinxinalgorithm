#include<bits/stdc++.h>
#include<unordered_map>
using namesapce std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return func(root,k,s);
    }
    bool func(TreeNode* root,int k,unordered_set<int>& s){
        if(!root) return false;
        if(s.count(k-root->val)) return true;
        s.insert(root->val);
        return func(root->left,k,s)||func(root->right,k,s);
    }
};