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
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return;
        flattenRecursive(root);
    }

private:
    TreeNode *flattenRecursive(TreeNode *root) {
        TreeNode *right_child = root->right, *left_child = root->left, *last = root;
        if (left_child) {
            last = flattenRecursive(left_child);
            root->right = left_child;
            last->right = right_child;
            root->left = last->left = NULL;
        }
        if (right_child) last = flattenRecursive(right_child);
        return last;
    }
};
class Solution {
public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // preorder traversal
        stack<TreeNode *> preorder_stack;
        TreeNode *current = root, *previous = NULL;
        while (!preorder_stack.empty() || current) {
            if (current) {
                if (current->right) preorder_stack.push(current->right);
                current->right = current->left;
                current->left = NULL;
                previous = current;
                current = current->right;
            } else {
                current = preorder_stack.top();
                preorder_stack.pop();
                previous->right = current;
            }
        }
        return;
    }
};
class Solution {
public:
    void flatten(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return;
        flattenRecursive(root, NULL);
    }

private:
    TreeNode *flattenRecursive(TreeNode *root, TreeNode *next) {
        if (!root) return next;
        next = flattenRecursive(root->right, next);
        next = flattenRecursive(root->left, next);
        root->left = NULL;
        root->right = next;
        return root;
    }
};