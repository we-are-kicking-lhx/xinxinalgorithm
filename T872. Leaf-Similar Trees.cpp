class Solution {
public:
    vector<int>ts;
    void find_seq(TreeNode *t){
        if(t->left == NULL && t->right == NULL){
            ts.push_back(t->val);
            return;
        }
        if(t->left!=NULL)find_seq(t->left);
        if(t->right!=NULL)find_seq(t->right);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1,t2;
        find_seq(root1);
        t1 = ts;
        ts.clear();
        find_seq(root2);
        t2 = ts;
        int n1 = t1.size(),n2 = t2.size();
        if (n1 != n2)return false;
        for (int i = 0; i < n1; i++) {
            if(t1[i] != t2[i])
                return false;
        }
        return true;
    }
};