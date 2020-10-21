class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *n_head = new ListNode(0);
        ListNode *last = n_head;
        last->next = head;
        ListNode *node = head;
        while(last&&node){
            while(node && node->val != val){
                node = node->next;
                last = last->next;
            }
            while(node && node->val==val)
                node = node->next;
            if(last)
                last->next = node;
        }
        return n_head->next;
    }
};