/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *find_mid(ListNode* head){
        ListNode *slow = head,*fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse_lst(ListNode* node){
        ListNode *prev = NULL; 
        ListNode *curr = node;
        while(curr){
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head)return;
        ListNode *mid = find_mid(head);
        ListNode *l2 = reverse_lst(mid->next);
        mid->next = NULL;
        ListNode *l1 = head;
        ListNode *l1_tmp,*l2_tmp;
        while(l1 && l2){
            l1_tmp = l1->next;
            l2_tmp = l2->next;
            l1->next = l2;
            l1 = l1_tmp;
            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};