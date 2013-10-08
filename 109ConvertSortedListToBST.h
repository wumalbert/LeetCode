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
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == head) return NULL;
        return genBST(head, NULL);
    }
private:
    // generate BST from [begin, end)
    TreeNode *genBST(ListNode *begin, ListNode *end) {
        if (begin == end) return NULL;
        ListNode *slow = begin, *fast = begin;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = genBST(begin, slow);
        root->right = genBST(slow->next, end);
        return root;
    }
};
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == head) return NULL;
        int begin = 0, end = 0;
        ListNode *list = head;
        for (; list; list = list->next) ++end;
        list = head;
        return genBST(list, begin, end);
    }
private:
    // generate BST from [begin, end]
    TreeNode *genBST(ListNode *&list, int begin, int end) {
        if (begin >= end) return NULL;
        int middle = begin + (end-begin >> 1);
        TreeNode *left = genBST(list, begin, middle);
        TreeNode *root = new TreeNode(list->val);
        root->left = left;
        list = list->next;
        root->right = genBST(list, middle+1, end);
        return root;
    }
};