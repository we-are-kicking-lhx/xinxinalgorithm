class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>v,TreeNode *root,int sum){
        v.push_back(root->val);
        if(!(root->left||root->right)){
            if(sum == root->val)
                res.push_back(v);
            return;
        }
        if(root->left)
            dfs(v,root->left,sum - root->val);
        if(root->right)
            dfs(v,root->right,sum - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root)
            dfs({},root,sum);
        return res;
    }
};