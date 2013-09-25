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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head) return NULL;
        
        ListNode *newHead = new ListNode(0);
        
        newHead->next = head;
        
        ListNode *pCurr = head, *pPrev = newHead;
        while (pCurr)
        {
            while (pCurr->next && pCurr->next->val == pCurr->val)
            {
                pCurr = pCurr->next;
            }
            if (pCurr != pPrev->next)
            {
                // delete the duplicates 
                ListNode *p = pPrev->next;
                pCurr = pCurr->next;
                while (p != pCurr)
                {
                    ListNode *q = p;
                    p = p->next;
                    delete q;
                }
                pPrev->next = pCurr;
            }
            else
            {
                pPrev = pCurr;
                pCurr = pCurr->next;
            }
        }
        
        head = newHead->next;
        delete newHead;
        return head;
    }
};