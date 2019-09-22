class Solution {
public:
    int res;
    vector<vector<int>>r;
    void dfs(TreeNode * t,int sum,vector<int>v){
        sum += t->val;
        v.push_back(t->val);
        if(sum == res && t->left == NULL && t->right == NULL)
            r.push_back(v);
        else{
            if(t->left != NULL)dfs(t->left,sum, v);
            if(t->right != NULL)dfs(t->right, sum, v);
        }
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res = sum;
        vector<int>v;
        if(root == NULL) return r;
        dfs(root, 0, v);
        return r;
    }
};
//因为存在负数节点所以不需要做剪枝