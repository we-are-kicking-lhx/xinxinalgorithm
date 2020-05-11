//递归
class Solution {
public:
    bool sym(TreeNode *n1,TreeNode *n2){
        if(!(n1||n2))
            return true;
        if(!(n1&&n2))
            return false;
        return n1->val==n2->val&&sym(n1->left,n2->right)&&sym(n1->right,n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return sym(root->left,root->right);
    }
};

//迭代
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode *>q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode *n1 = q.front();
            q.pop();
            TreeNode *n2 = q.front();
            q.pop();
            if(!(n1||n2))
                continue;
            if((!(n1&&n2)) || n1->val!=n2->val)
                return false;
            q.push(n1->left);
            q.push(n2->right);
            q.push(n1->right);
            q.push(n2->left);
        }
        return true;
    }
};