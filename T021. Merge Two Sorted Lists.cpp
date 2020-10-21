class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1,*curr2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *node = head;
        while(curr1 && curr2){
            if (curr1->val <= curr2->val){
                node->next = curr1;
                node = node->next;
                curr1 = curr1->next;
            }
            else if (curr1->val >= curr2->val){
                node->next = curr2;
                node = node->next;
                curr2 = curr2->next;
            }
        }
        if(curr1)
            node->next = curr1;
        if(curr2)
            node->next = curr2;
        return head->next;    
        
    }
};