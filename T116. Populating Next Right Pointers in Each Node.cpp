class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            int level_numbers = q.size();
            Node *last = NULL;
            while(level_numbers--){
                Node *node = q.front();
                q.pop();
                if(last)
                    last->next = node;
                last = node;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            last->next = NULL;
        }
        return root;
    }
};