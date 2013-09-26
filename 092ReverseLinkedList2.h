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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *newHead = new ListNode(0);
        newHead->next = head;

        ListNode *pTailFront = newHead, *pTailBack = newHead, *pNode = head;
        int count = 1;
        while(pNode && count < m)
        {
            pTailFront = pNode;
            pNode = pNode->next;
            ++count;
        }
        pTailBack = pNode;
        pNode = pNode->next;
        ++count;
        while(pNode && count <= n)
        {
            ListNode *t = pNode->next;
            pNode->next = pTailFront->next;
            pTailFront->next = pNode;
            
            pNode = t;
            ++count;
        }
        
        pTailBack->next = pNode;
        
        head = newHead->next;
        delete newHead;
        return head;
    }
};