//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int d_l = maxDepth(root->left);
        int d_r = maxDepth(root->right);
        return max(d_l,d_r)+1;
    }
};

//迭代
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int cnt = 0;
        if(!root)
            return 0;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            cnt++;
            int level_numbers = q.size();
            while(level_numbers--){
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return cnt;
    }
};