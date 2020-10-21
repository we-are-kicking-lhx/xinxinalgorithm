class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *head0 = new ListNode(0);
        head0->next = head;
        ListNode* pos = head0;
        while(pos->next && pos->next->next){
            ListNode* node1=pos->next;
            ListNode* node2=pos->next->next;
            node1->next = node2->next;
            pos->next = node2;
            node2->next = node1;
            pos = node1;
        }
        return head0->next;
    }
};