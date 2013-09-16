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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        
        ListNode *newHead, *last, *prev, *curr;
        prev = head;
        curr = head->next;
        
        if (!curr) return head;
        else
        {
            newHead = curr;
            
            last = curr->next;
            curr->next = prev;
            prev->next = last;
            
            last = prev;
            curr = last->next;
        }
        
        while (curr && curr->next)
        {
            prev = curr;
            curr = curr->next;
            
            last->next = curr;
            
            last = curr->next;
            curr->next = prev;
            prev->next = last;
            
            last = prev;
            curr = last->next;
        }
        
        return newHead;
    }
};