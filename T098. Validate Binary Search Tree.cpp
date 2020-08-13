//递归
class Solution {
public:
    vector<int>res;
    void dfs(TreeNode* root){
        if(root->left)
            dfs(root->left);
        res.emplace_back(root->val);
        if(root->right)
            dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        dfs(root);
        for(int i = 1;i < res.size();i++){
            if(res[i] <= res[i-1])
                return false;
        }
        return true;
    }
};
//迭代
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        vector<int>res;
        stack<TreeNode *>s;
        TreeNode * node = root;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            res.emplace_back(node->val);
            node = node->right;
        }
        for(int i = 1;i < res.size();i++){
            if(res[i-1] >= res[i])
                return false;
        }
        return true;
    }
};