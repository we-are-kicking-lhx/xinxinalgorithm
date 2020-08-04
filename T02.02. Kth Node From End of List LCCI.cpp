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
    int kthToLast(ListNode* head, int k) {
        ListNode *l,*r;
        l = head;
        while(k--){
            l = l->next;
        }
        r = head;
        while(l){
            l = l->next;
            r = r->next;
        }
        return r->val;
    }
};
