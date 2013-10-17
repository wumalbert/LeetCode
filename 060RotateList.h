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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || k <= 0) return head;
        int count = 0;
        ListNode *slow = head, *fast = head;
        for (; fast; fast = fast->next) ++count;
        k = k % count;
        if (0 == k) return head;
        count = 0;
        fast = head;
        while (count < k && fast) {
            fast = fast->next; 
            ++count;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || k <= 0) return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next) {
            tail = tail->next;
            ++len;
        }
        k = (len - k%len) % len;
        if (k == 0) return head;
        ListNode *node = head;
        while (k > 1) {
            node = node->next;
            --k;
        }
        tail->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
};