class Solution {
public:
    bool helper(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val == root->val){
            return helper(head->next,root->left) || helper(head->next,root->right);
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(head->val == node->val && helper(head,node))
                return true;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return false;
    }
};