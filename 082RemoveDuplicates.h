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
        if (NULL == head) return head;
        
        ListNode *pPrev = head, *pCurr = head->next;
        while (pCurr)
        {
            if (pCurr->val == pPrev->val)
            {
                pPrev->next = pCurr->next;
                delete pCurr;
                pCurr = pPrev->next;
            }
            else
            {
                pPrev = pCurr;
                pCurr = pCurr->next;
            }
        }
        
        return head;
    }
};