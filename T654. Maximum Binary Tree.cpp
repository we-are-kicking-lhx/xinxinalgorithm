class Solution {
public:
    vector<int>tree;
    TreeNode* dfs(int start,int end){
        if(start > end)return NULL;
        int pos = max_element(tree.begin()+start,tree.begin()+end+1) - tree.begin();
        TreeNode *root = new TreeNode(tree[pos]);
        root->left = dfs(start,pos - 1);
        root->right = dfs(pos + 1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        tree = nums;
        return dfs(0,nums.size()-1);
    }
};