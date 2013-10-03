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