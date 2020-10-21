class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head,*fast=head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *last = NULL;
        while(slow){
            ListNode *node = slow->next;
            slow->next = last;
            last = slow;
            slow = node;
        }
        slow = head;
        while(slow!=last){
            if(slow->val!=last->val)
                return false;
            if(slow->next == last){
                break;
            }
            slow = slow->next;
            last = last->next;
        }
        return true;
    }
};