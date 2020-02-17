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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        ListNode* p=head;
        ListNode* q=p->next;
        while(q){
            int temp=p->val;
            p->val=q->val;
            q->val=temp;
            if(!q->next) break;
            p=q->next;
            q=q->next->next;
        }
        return head;
    }
};