public:
    int res = 32767;
    void dfs(TreeNode* root,int d){
        if (root->left == NULL && root->right == NULL){
            res = res < d ? res : d;
            return;
        }
        if(d < res){
            if (root -> left)dfs(root -> left, d + 1);
            if (root -> right)dfs(root -> right, d + 1);
        }
    }
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root, 1);
        return res;
    }
};