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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *head = new ListNode(-1); // set a sentinel node
        ListNode *tail = head;
        
        ListNode *p1 = l1, *p2 = l2;
        while (p1 && p2)
        {
            if (p1->val < p2->val)
            {
                tail->next = p1;
                p1 = p1->next;
                tail = tail->next;
            }
            else
            {
                tail->next = p2;
                p2 = p2->next;
                tail = tail->next;
            }
        }
        
        if (!p1) tail->next = p2;
        else if (!p2) tail->next = p1;
        
        tail = head;
        head = head->next;
        delete tail;
        return head;
    }
};