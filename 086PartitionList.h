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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        
        ListNode *pTail = newHead, *pCurr = newHead;
        while (pCurr->next)
        {
            if (pCurr->next->val >= x)
            {
                pCurr = pCurr->next;
            }
            else if (pCurr != pTail)
            {
                ListNode *t = pCurr->next;
                pCurr->next = t->next;
                t->next = pTail->next;
                pTail->next = t;
                pTail = pTail->next;
            }
            else
            {
                pTail = pTail->next;
                pCurr = pTail;
            }
        }
        
        head = newHead->next;
        delete newHead;
        return head;
    }
};