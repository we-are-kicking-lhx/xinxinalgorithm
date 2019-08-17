class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return root;
        queue<Node *>q;
        q.push(root);
        while (!q.empty()) {
            int cnt = q.size();
            Node * next = NULL;
            while (cnt--) {
                Node * n = q.front();
                q.pop();
                n->next = next;
                if (n->left != NULL) {
                    q.push(n->right);
                    q.push(n->left);
                }
                next = n;
            }
        }
        return root;
    }
};