class Solution {
public:
    vector<int>pre_o,in_o;
    int cnt = 0;
    TreeNode * make_tree(int begin,int end){
        if(begin > end)
            return NULL;
        int root = pre_o[cnt++];
        TreeNode *t = new TreeNode(root);
        if(begin < end){
            int pos =find(in_o.begin() + begin, in_o.begin() + end,root) - in_o.begin();
            t -> left = make_tree(begin, pos - 1) ;
            t -> right = make_tree(pos + 1, end);
        }
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(!n)
            return NULL;
        pre_o = preorder;
        in_o = inorder;
        TreeNode * t = make_tree(0, n - 1);
        return t;
    }
};