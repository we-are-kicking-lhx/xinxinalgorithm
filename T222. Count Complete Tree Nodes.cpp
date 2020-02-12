class Solution {
public:
    int d = 0;
    int n = 0;
    void countDepth(TreeNode* root){
        while (root->left != NULL){
            root = root->left;
            d++;
        }
        n = pow(2, d);
    }
    int exist(int idx,TreeNode* root){
        int nd = d;
        int left = 0,right = n - 1;
        while (nd--) {
            int mid =(left + right) / 2;
            if(idx > mid){
                left = mid + 1;
                root = root->right;
            }
            else{
                right = mid;
                root = root->left;
            }
        }
        if(root == NULL)return 0;
        return 1;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        countDepth(root);
        if(d == 0)return 1;
        int left = 0,right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if(exist(mid, root)){
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }
        return n - 1 + left;
    }
};