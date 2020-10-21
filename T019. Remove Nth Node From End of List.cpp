class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *node1=head,*node2;
        ListNode *dhead = new ListNode(0);
        dhead->next = head;
        node2 = dhead;
        while(n--)
            node1 = node1->next;
        while(node1){
            node1 = node1->next;
            node2 = node2->next;
        }
        node2->next = node2->next->next;
        return dhead->next;
    }
};