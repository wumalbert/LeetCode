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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *tail = NULL;
        
        while (true)
        {
            int minVal = numeric_limits<int>::max();
            int minIndex = -1;
            for(size_t i = 0; i < lists.size(); ++i)
            {
                if (NULL != lists[i] && lists[i]->val < minVal)
                {
                    minVal = lists[i]->val;
                    minIndex = i;
                }
            }
            
            if (-1 == minIndex)
            {
                break;
            }
            
            if (NULL == head)
            {
                head = lists[minIndex];
                tail = head;
            }
            else
            {
                tail->next = lists[minIndex];
                tail = tail->next;
            }
            
            lists[minIndex] = lists[minIndex]->next;
        }
        
        return head;
    }
};