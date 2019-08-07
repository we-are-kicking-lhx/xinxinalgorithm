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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder,0,preorder.size());
    }
    TreeNode* func(vector<int>& preorder,int p,int q){
        if(p>=q) return nullptr;
        auto root= new TreeNode(preorder[p]);
        int temp=p;
        while(temp<q && preorder[temp]<=root->val) temp++;
        root->left=func(preorder,p+1,temp);
        root->right=func(preorder,temp,q);
        return root;
    }
};