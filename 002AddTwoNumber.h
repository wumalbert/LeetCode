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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *result = new ListNode(-1); //sentinel node
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *r = result;
        
        int carry = 0;
        while (p1 && p2)
        {
            int sum = p1->val + p2->val + carry;
            carry = sum / 10;
            r->next = new ListNode(sum % 10);
            
            p1 = p1->next;
            p2 = p2->next;
            r = r->next;
        }
        
        // let p1 pointer to the null list
        if (p2) p1 = p2;
        while (p1)
        {
            int sum = p1->val + carry;
            carry = sum / 10;
            r->next = new ListNode(sum % 10);
            
            p1 = p1->next;
            r = r->next;
        }
        if (carry)
            r->next = new ListNode(1);
        
        r = result;
        result = result->next;
        delete r;
        return result;
    }
};