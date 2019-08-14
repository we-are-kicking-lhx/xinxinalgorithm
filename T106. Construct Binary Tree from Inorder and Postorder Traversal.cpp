class Solution {
public:
    vector<int>post_o,in_o;
    int cnt;
    TreeNode * make_tree(int begin,int end){
        if(begin > end)
            return NULL;
        int root = post_o[cnt--];
        TreeNode *t = new TreeNode(root);
        if(begin < end){
            int pos =find(in_o.begin() + begin, in_o.begin() + end,root) - in_o.begin();
            t -> right = make_tree(pos + 1, end);
            t -> left = make_tree(begin, pos - 1) ;
        }
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(!n)return NULL;
        cnt = n - 1;
        post_o = postorder;
        in_o = inorder;
        TreeNode * t = make_tree(0, n - 1);
        return t;
    }
};