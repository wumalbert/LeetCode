/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution01 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;
        while (l1 && l2) {
            tail->next = new ListNode((l1->val + l2->val + carry) % 10);
            tail = tail->next;
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l2) l2 = l1;
        while (l2) {
            tail->next = new ListNode((l2->val + carry) % 10);
            tail = tail->next;
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        }
        if (carry > 0) tail->next = new ListNode(carry);
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;
        int sum;
        while (l1 || l2 || carry) {
            sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            carry = sum / 10;
        }
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};