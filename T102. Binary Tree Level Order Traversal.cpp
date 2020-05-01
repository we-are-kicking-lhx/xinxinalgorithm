class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int level_numbers = q.size();
            vector<int>temp;
            while(level_numbers--){
                TreeNode *node = q.front();
                q.pop();
                temp.emplace_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            res.emplace_back(temp);
        }
        return res;
    }
};