/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// recursive solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        else if (!l2) return l1;
        ListNode *head;
        if (l1->val < l2->val) {
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        } else {
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
};

// insertion sort solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *head = new ListNode(0);
        head->next = l1;
        l1 = head;
        while (l2) {
            while (l1->next && l1->next->val < l2->val) l1 = l1->next;
            if (!l1->next) {
                l1->next = l2;
                break;
            } else {
                ListNode *t = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l1 = l1->next;
                l2 = t;
            }
        }
        ListNode *t = head;
        head = head->next;
        delete t;
        return head;
    }
};

// two pointer solution
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *ret = NULL;
        ListNode **current = &ret;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                *current = l1;
                l1 = l1->next;
            } else {
                *current = l2;
                l2 = l2->next;
            }
            current = &((*current)->next);
        }
        *current = l1 ? l1 : l2;
        return ret;
    }
};