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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    TreeNode* buildTree(vector<int>::iterator preBegin,vector<int>::iterator preEnd,vector<int>::iterator inBegin,vector<int>::iterator inEnd){
        if(preBegin==preEnd) return NULL;
        
    } 
};