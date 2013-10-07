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
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head, *tail = dummy;
        int last = 0;
        while (current) {
            if ((current != head && current->val == last) || (current->next && current->next->val == current->val)) {
                last = current->val;
                tail->next = current->next;
                delete current;
                current = tail->next;
            } else {
                last = current->val;
                tail->next = current;
                current = current->next;
                tail = tail->next;
            }
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
        if (!head || !head->next) return head;
        ListNode *p = head->next;
        if (p->val != head->val) {
            head->next = deleteDuplicates(p);
        } else {
            while (p && p->val == head->val) p = p->next;
            ListNode *t;
            while (head != p) {
                t = head;
                head = head->next;
                delete t;
            }
            head = deleteDuplicates(p); 
        }
        return head;
    }
};