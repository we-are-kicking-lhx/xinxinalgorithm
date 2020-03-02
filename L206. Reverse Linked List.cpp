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
    ListNode* reverseList(ListNode* head) {
        ListNode* p=NULL;
        ListNode* q=head;
        while(q!=NULL){
            ListNode* temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        return p;
    }
};

