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
    void inorderTraversal(TreeNode *root, TreeNode* &previous, TreeNode* &n1, TreeNode* &n2) {
        if (!root) return;
        inorderTraversal(root->left, previous, n1, n2);
        if (previous && previous->val > root->val) {
            n2 = root;
            if (!n1) n1 = previous;
        }
        previous = root;
        inorderTraversal(root->right, previous, n1, n2);
    }
    
public:
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return;
        TreeNode *previous = NULL, *n1 = NULL, *n2 = NULL;
        inorderTraversal(root, previous, n1, n2);
        if (n1 != n2) {
            n1->val = n1->val ^ n2->val;
            n2->val = n1->val ^ n2->val;
            n1->val = n1->val ^ n2->val;
        }
    }
};
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeNode *current = root, *previous = NULL, *first = NULL, *second = NULL;
        while (current) {
            if (current->left) {
                TreeNode *node = current->left;
                while (node->right && node->right != current) node = node->right;
                if (!node->right) {
                    node->right = current;
                    current = current->left;
                } else {
                    node->right = NULL;
                    previous = node;
                    if (previous && current->val < previous->val) {
                        second = current;
                        if (!first) first = previous;
                    }
                    previous = current;
                    current = current->right;
                }
            } else {
                if (previous && current->val < previous->val) {
                    second = current;
                    if (!first) first = previous;
                }
                previous = current;
                current = current->right;
            }
        }
        first->val = first->val ^ second->val;
        second->val = first->val ^ second->val;
        first->val = first->val ^ second->val;
    }
};
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        stack<TreeNode*> inorder_stack;
        TreeNode *current = root, *previous = NULL, *first = NULL, *second = NULL;
        while (!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current = current->left;
            } else {
                current = inorder_stack.top();
                inorder_stack.pop();
                if (previous && current->val < previous->val) {
                    if (!first) {
                        first = previous;
                        second = current;
                    } else {
                        second = current;
                    }
                }
                previous = current;
                current = current->right;
            }
        }
        first->val = first->val ^ second->val;
        second->val = first->val ^ second->val;
        first->val = first->val ^ second->val;
    }
};