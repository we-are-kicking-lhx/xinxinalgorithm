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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        string path;
        dfs(root,path);
        return res;
    }
    void dfs(TreeNode* root,string path){
        if(!root) return;
        path+="->"+to_string(root->val);
        if(!root->left && !root->right) {
            res.push_back(path.substr(2,path.length()-1));
            return;
        }
        dfs(root->left,path);
        dfs(root->right,path);
    }
};