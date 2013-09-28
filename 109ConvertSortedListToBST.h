/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *sortedListToBST(const ListNode *begin, const ListNode *end)
    {
        if (begin == end) return NULL;
        
        const ListNode *slow = begin, *fast = begin;
        while (fast != end)
        {
            if (fast->next == end) break;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(begin, slow);
        root->right = sortedListToBST(slow->next, end);
        
        return root;
    }
    
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        return sortedListToBST(head, NULL);
    }
};