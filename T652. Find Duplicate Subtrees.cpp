class Solution {
public:
    unordered_map<string,int>hashmap;
    vector<TreeNode*>ans;
    string dfs(TreeNode* node){
        if(node == NULL)
            return "#";
        string left = dfs(node->left);
        string right = dfs(node->right);
        string s = to_string(node->val) + left + right;
        if(hashmap[s] == 1)ans.push_back(node);
        hashmap[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};