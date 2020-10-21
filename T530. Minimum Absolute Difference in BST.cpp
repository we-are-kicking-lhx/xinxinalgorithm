class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int last = 1000000;
        int ans = 1000000;
        stack<TreeNode *>s;
        TreeNode * node = root;
        while(node || !s.empty()){
            while(node){
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            ans = min(ans,abs(node->val - last));
            last = node->val;
            node = node->right;
        }
        return ans;
    }
};