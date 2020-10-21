class Solution {
public:
    Node *dfs(Node *prev,Node *node){
        if(!node)
            return prev;
        prev->next = node;
        node->prev = prev;
        Node *next = node->next;
        Node *tail = dfs(node,node->child);
        node->child = NULL;
        return dfs(tail,next);
        
    }
    Node* flatten(Node* head) {
        if(!head)return NULL;
        Node *node = new Node(0,NULL,head,NULL);
        dfs(node,head);
        head->prev = NULL;
        return head;
    }
};