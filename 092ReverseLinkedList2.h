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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return head;
        ListNode *dummy = new ListNode(0), *tail = dummy, *current = head;
        dummy->next = head;
        int count = 1;
        while (count < m) {
            current = current->next;
            tail = tail->next;
            ++count;
        }
        ListNode *reverse_tail = current;
        while (count <= n) {
            ListNode *next = current->next;
            current->next = tail->next;
            tail->next = current;
            current = next;
            ++count;
        }
        reverse_tail->next = current;
        head = dummy->next;
        delete dummy;
        return head;
    }
};