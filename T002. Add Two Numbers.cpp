class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s = 0;
        ListNode *node1 = l1,*node2 = l2,*last;
        while(node1 || s || node2){
            int a = node1 ? node1->val : 0;
            int b = node2 ? node2->val : 0;
            int add = s + a + b;
            s = add >= 10 ? 1 : 0;
            if(node1)
                node1->val = add % 10;
            else{
                node1 = new ListNode(add % 10);
                last->next = node1;
            }
            last = node1;
            node1 = node1->next;
            node2 = node2 ? node2->next : node2;
        }
        return l1;
    }
};