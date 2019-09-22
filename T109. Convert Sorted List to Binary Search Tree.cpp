class Solution {
public:
    int node[32767];
    TreeNode* build_tree(int left, int right){
        int mid = (right + left)/2;
        TreeNode* n = new TreeNode(node[mid]);
        if (left > right)
            return NULL;
        else if (left != right){
            n->left = build_tree(left, mid - 1);
            n->right = build_tree(mid + 1, right);
        }
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        while (head != NULL) {
            node[cnt++] = head->val;
            head = head -> next;
        }
        int left = 0,right = cnt - 1;
        return build_tree(left, right);
    }
};
