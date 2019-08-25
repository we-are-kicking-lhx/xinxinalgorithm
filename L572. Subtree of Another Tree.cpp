class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(isSame(s,t)) return true;
        else return isSubtree(s->left,t) || isSubtree(s->right,t);

    }
    bool isSame(TreeNode* t1,TreeNode* t2){
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(t1->val==t2->val) return isSame(t1->left,t2->left) && isSame(t1->right,t2->right);
        else return false;
    }
};