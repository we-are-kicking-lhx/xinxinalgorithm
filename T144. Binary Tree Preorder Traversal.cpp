//递归
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};


//迭代
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode *>s;
        if(root == NULL)
            return res;
        s.push(root);
        while(!s.empty()){
            TreeNode *node = s.top();
            res.push_back(node->val);
            s.pop();
            if(node->right != NULL)
                s.push(node->right);
            if(node->left != NULL)
                s.push(node->left);
        }
        return res;
    }
};