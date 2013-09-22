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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return head;
        
        ListNode *fast, *slow;
        slow = fast = head;
        int len = 0;
        while (fast)
        {
            ++len;
            fast = fast->next;
        }
        k = k % len;
        
        fast = head;
        int count = 0;
        while (count < k && fast)
        {
            // if (NULL == fast->next) fast->next = head;
            fast = fast->next;
            ++count;
        }
        
        if (!fast) return head;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        fast = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
    }
};