class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        ListNode *head2 = head->next;
        ListNode *node1 = head,*node2 = head2;
        while(node2 && node2->next){
            node1->next = node2->next;
            node1=node1->next;
            node2->next = node1->next;
            node2=node2->next;
        }
        node1->next = head2;
        return head;
    }
};