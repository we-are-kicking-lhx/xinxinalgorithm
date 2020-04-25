//递归
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* node){
        if(node == NULL)
            return;
        if(node->left!=NULL)
            dfs(node->left);
        res.push_back(node->val);
        if(node->right!=NULL)
            dfs(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};
//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>res;
        if(root==NULL)
            return res;
        s.push(root);
        int is_leaf = 0;
        while(!s.empty()){
            TreeNode * node = s.top();
            while(!is_leaf && node->left!=NULL){
                s.push(node->left);
                node = node->left;
            }
            node = s.top();
            res.push_back(node->val);
            s.pop();
            if(node->right!=NULL){
                s.push(node->right);
                is_leaf = 0;
            }
            else
                is_leaf = 1;
        }
        return res;
    }
};