class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1,s2;
        dfs(root1,s1);
        dfs(root2,s2);
        return s1==s2;
    }
    void dfs(TreeNode* node,vector<int>& s){
        if(!node) return;
        if(!node->left && !node->right)
            s.push_back(node->val);
        dfs(node->left,s);
        dfs(node->right,s);
    }
};