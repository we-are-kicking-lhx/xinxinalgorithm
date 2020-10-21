class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        while(fast){
            slow = slow->next;
            if(!fast->next)
                return NULL;
            fast = fast->next->next;

            if(slow == fast){
                while(head != slow){
                    head = head->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
//1.判断单链表是否有环:快慢指针，相遇有环
//2.找出环入口:相遇后，头指针和慢指针的相遇点为入口
//3.环内元素个数:相遇后:slow指针遍历相同|fast和slow再次相遇
//4.环内最远距离:快慢指针从入口开始，到fast再次到入口，slow的位置
//5.两个链表是否相交:两个链表连接，双指针，相遇则相交