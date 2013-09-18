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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (!head) return NULL; // NULL list
        
        if (k <= 1) return head;
        
        ListNode *newHead = new ListNode(-1); //set a sentinel head node
        ListNode *tail = newHead; //the tail node of the last group, insert each node after this tail node
        
        ListNode *start = head;
        ListNode *end = head;
        while (true)
        {
            int count = 1;
            start = end;
            while (end && count < k)
            {
                end = end->next;
                ++count;
            }
            
            if (end && count >= k) // to reverse the inteval
            {
                ListNode *newTail = start; //preserve the new tail of this group
                ListNode *next;
                while (start != end)
                {
                    next = start->next;
                    start->next = tail->next;
                    tail->next = start;
                    start = next;
                }
                end = end->next;
                start->next = tail->next;
                tail->next = start;
                
                tail = newTail;
            }
            else 
            {
                tail->next = start;
                
                // delete the sentinel head node
                tail = newHead;
                newHead = newHead->next;
                delete tail;
                
                return newHead;
            }
        }
    }
};