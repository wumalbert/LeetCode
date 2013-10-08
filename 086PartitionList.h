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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy, *tail = dummy;
        while (current->next) {
            if (current->next->val >= x) {
                current = current->next;
            } else if (current == tail) {
                current = tail = current->next;
            } else {
                ListNode *t = current->next;
                current->next = current->next->next;
                t->next = tail->next;
                tail->next = t;
                tail = tail->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};