/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode h=ListNode(0);
        h.next=head;
        ListNode* p=&h;
        ListNode* q=p;
        for(int i=0;i<=n;i++)
            q=q->next;
        while(q){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return h.next;
    }
};