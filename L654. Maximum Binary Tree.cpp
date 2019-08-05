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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        auto maxpos=max_element(nums.begin(),nums.end());
        TreeNode* root=new TreeNode(*maxpos);
        root->left=constructMaximumBinaryTree(* new vector<int>(nums.begin(),maxpos));
        root->right=constructMaximumBinaryTree(* new vector<int>(maxpos+1,nums.end()));
        return root;
    }
};