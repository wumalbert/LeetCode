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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *current = head, *tail = dummy;
        while (current->next) {
            if (current->next->val != current->val) {
                tail->next = current;
                tail = current;
            } else {
                tail->next = current->next;
                delete current;
            }
            current = current->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == head) return head;
        ListNode *previous = head, *current = head->next;
        while (current) {
            if (current->val == previous->val) {
                previous->next = current->next;
                delete current;
                current = previous->next;
            } else {
                previous = current;
                current = current->next;
            }
        }
        return head;
    }
};