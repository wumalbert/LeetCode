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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == head || k <= 0) return head;
        int size = 0;
        for (ListNode *node = head; node != NULL; node = node->next) ++size;
        ListNode *dummy = new ListNode(0), *tail = dummy, *node = head;
        while (size >= k) {
            ListNode *new_tail = node;
            for (int i = 0; i < k; ++i) {
                ListNode *next = node->next;
                node->next = tail->next;
                tail->next = node;
                node = next;
            }
            tail = new_tail;
            size -= k;
        }
        tail->next = node;
        head = dummy->next;
        delete dummy;
        return head;
    }
};