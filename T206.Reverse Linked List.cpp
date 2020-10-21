class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode *last = head,*node = head->next;
        last ->next = NULL;
        while(node != NULL){
            ListNode *next = node->next;
            node->next = last;
            last = node;
            node = next;
        }
        return last;
    }
};