//迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode * t1 = q.front();
            q.pop();
            TreeNode * t2 = q.front();
            q.pop();
            if (t1 == NULL && t2 == NULL)
                continue;
            if (t1 == NULL || t2 == NULL)
                return false;
            if (t1 -> val != t2 -> val )
                return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;  
    }
};


//递归
class Solution {
public:
    bool sym(TreeNode *t1,TreeNode*t2){
        if (t1 == NULL && t2 == NULL)
            return true;
        if (t1 == NULL || t2 == NULL)
            return false;
        return (t1->val == t2->val) && sym(t1->left, t2->right) && sym(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return sym(root->left, root->right);
    }
};