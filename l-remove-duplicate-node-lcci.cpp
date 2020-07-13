class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head)
    {
        if (!head)
            return NULL;
        ListNode* h = head;
        unordered_set<int> s { head->val };
        while (h->next) {
            if (s.count(h->next->val)) {
                h->next = h->next->next;
            } else {
                s.insert(h->next->val);
                h = h->next;
            }
        }
        h->next = NULL;
        return head;
    }
};