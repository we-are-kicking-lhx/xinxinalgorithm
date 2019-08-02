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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)  return {};
        vector<vector<int>> res;
        queue<TreeNode* > q{{root}};
        while(!q.empty()){
            vector<int> temp;
            for(int i=q.size()-1;i>=0;i--){
                TreeNode* node=q.front();q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                temp.push_back(node->val);
            }
            res.insert(res.begin(),temp);
        }
        return res;
    }
};