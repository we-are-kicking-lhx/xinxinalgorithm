class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p_a = headA,*p_b = headB;
        while(p_a != p_b){
            if(p_a == NULL)
                p_a = headB;
            else
                p_a = p_a->next;
            if(p_b == NULL)
                p_b = headA;
            else
                p_b = p_b->next;            
        }
        return p_a;
    }
};