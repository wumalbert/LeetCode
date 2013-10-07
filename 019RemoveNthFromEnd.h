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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *fast=head, *slow=head;
        int count = 0;
        while (fast && count < n) {
            ++count;
            fast = fast->next;
        }
        if (!fast && n == count) { // the Nth node is the head node
            slow = head;
            head = head->next;
            delete slow;
            return head;
        }
        else if (!fast) return NULL;
        else {
            while (fast->next) {
                fast = fast->next;
                slow = slow->next;
            }
            fast = slow->next;
            slow->next = fast->next;
            delete fast;
            return head;
        }
    }
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode **fast=&head, **slow=&head;
        for (int i = 0; i < n; ++i) fast = &((*fast)->next);
        while (*fast) {
            fast = &((*fast)->next);
            slow = &((*slow)->next);
        }
        ListNode *node = *slow;
        *slow = (*slow)->next;
        delete node;
        return head;
    }
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;
        ListNode *fast=head, *slow=newHead;
        for (int i = 0; i < n; ++i) fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        head = newHead->next;
        delete newHead;
        return head;
    }
};