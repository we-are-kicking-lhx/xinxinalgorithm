class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(!(root->left||root->right)){
            if(sum != root->val)
                return false;
            return true;
        }
        if(root->left)
            if(hasPathSum(root->left,sum - root->val))
                return true;
        if(root->right)
            if(hasPathSum(root->right,sum - root->val))
                return true;
        return false;
            
    }
};