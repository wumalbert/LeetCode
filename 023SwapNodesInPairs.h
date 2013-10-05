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
    ListNode *swapPairs(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *current = head, **ret = &head;
        while (current && current->next) {
            ListNode *previous = current;
            current = current->next;
            previous->next = current->next;
            current->next = previous;
            *ret = current;
            current = previous->next;
            ret = &(previous->next);
        }
        return head;
    }
};