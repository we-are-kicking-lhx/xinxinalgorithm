/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        queue<TreeNode*> ans;
        vector<vector<int>> re;
        int cnt = 1;
        ans.push(root);
        while (!ans.empty()) {
            int n = 0;
            vector<int> child_vector;
            for (int i = 0; i < cnt; i++) {
                TreeNode* front = ans.front();
                if (front->left) {
                    ans.push(front->left);
                    n++;
                }
                if (front->right) {
                    ans.push(front->right);
                    n++;
                }
                child_vector.push_back(front->val);
                ans.pop();
            }
            cnt = n;
            re.push_back(child_vector);
        }
        return re;
    }
};