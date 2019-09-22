class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* node = new ListNode(-1);
		ListNode* re = node;
		ListNode* p = l1;
		ListNode* q = l2;
		int temp = 0;
		while (p || q || temp != 0) {
			if (p) { temp += p->val; p = p->next; }
			if (q) { temp += q->val; q = q->next; }
			node->next = new ListNode(temp % 10);
			node = node->next;
			temp = temp / 10;
		}
		return re->next;
	}
};