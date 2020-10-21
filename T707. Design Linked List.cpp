class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct LinkNode{
        int val;
        LinkNode * next = NULL;
        LinkNode(int val){
            this->val = val;
        }
    };
    
    LinkNode * HEAD = NULL;
    int len = 0;
    MyLinkedList() {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= len)
            return -1;
        LinkNode * node = HEAD;
        while(index--)
            node = node -> next;
        return node->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode *node = new LinkNode(val);
        node->next = HEAD;
        HEAD = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode * node = HEAD;
        while(node != NULL){
            if(node->next == NULL)
                break;
            node = node->next;
        }
        if(node == NULL)
            HEAD = new LinkNode(val);
        else
            node->next = new LinkNode(val);
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > len)
            return;
        if(HEAD == NULL || index == 0){
            addAtHead(val);
            return;
        }
        if(index == len){
            addAtTail(val);
            return;
        }
        LinkNode * node = HEAD;
        int last = index - 1;
        while(last > 0){
            node = node -> next;
            last--;
        }
        LinkNode *temp = node->next;
        node->next = new LinkNode(val);
        node->next->next = temp;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= len)
            return;
        if(index == 0){
            HEAD = HEAD->next;
            return;
        }
        LinkNode * node = HEAD;
        while(--index > 0)
            node = node -> next;
        LinkNode * d_node = node->next;
        node->next = node->next->next;
        delete(d_node);
        len--;
    }
};