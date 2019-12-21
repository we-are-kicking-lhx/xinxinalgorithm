class Solution {
public:
    vector<int>v;
    bool isValidBST(TreeNode* root) {
        dfs(root);
        if(v.size() <= 1)
            return true;
        for(int i = 1;i < v.size();i++){
            if(v[i] <= v[i-1])
                return false;
        }
        return true;
    }
    void dfs(TreeNode* root){
        if (root == NULL)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};
//二叉搜索树要求所有左子树的结点小于当前结点，所有右子树的结点大于当前结点