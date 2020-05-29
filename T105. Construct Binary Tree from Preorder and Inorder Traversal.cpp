class Solution {
public:
    vector<int>pre,ino;
    int cnt = 0;
    TreeNode* make_tree(int s,int e){
        if(s > e)
            return NULL;
        int val = pre[cnt++];
        TreeNode *node = new TreeNode(val);
        if(s < e){
            int pos = find(ino.begin()+s,ino.begin()+e,val)-ino.begin();
            node->left = make_tree(s,pos-1);
            node->right = make_tree(pos+1,e);
        }
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        ino = inorder;
        return make_tree(0,inorder.size()-1);
    }
};