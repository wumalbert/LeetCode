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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head) return NULL;
        
        ListNode *pCurrent, *pBefore;
        
        pCurrent = head;
        while (pCurrent && n > 0)
        {
            pCurrent = pCurrent->next;
            --n;
        }
        
        if (!pCurrent && n > 0) return NULL; // n is larger than the length
        
        if (!pCurrent && n == 0) //delete the head node
        {
            pCurrent = head;
            head = head->next;
            delete pCurrent;
            
            return head;
        }
        
        pBefore = head;
        while (pCurrent->next)
        {
            pCurrent = pCurrent->next;
            pBefore = pBefore->next;
        }
        
        pCurrent = pBefore->next;
        pBefore->next = pCurrent->next;
        
        delete pCurrent;
        
        return head;
    }
};