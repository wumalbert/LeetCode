/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// recursive DFS
class Solution03 {
public:
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        int low, high;
        return isValidBST(root, low, high);
    }
private:
    bool isValidBST(TreeNode *root, int &low, int &high) {
        low = high = root->val;
        if (root->left) {
            if (root->left->val >= root->val) return false;
            int left_low, left_high;
            if (!isValidBST(root->left, left_low, left_high) || left_high >= root->val) return false;
            low = left_low;
        } 
        if (root->right) {
            if (root->right->val <= root->val) return false;
            int right_low, right_high;
            if (!isValidBST(root->right, right_low, right_high) || right_low <= root->val) return false;
            high = right_high;
        }
        return true;
    }
};
// recursive DFS
class Solution02 {
public:
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (root->left) {
            TreeNode *left = root->left;
            while (left->right) left = left->right;
            if (left->val >= root->val) return false;
        }
        if (!isValidBST(root->right)) return false;
        if (root->right) {
            TreeNode *right = root->right;
            while (right->left) right = right->left;
            if (right->val <= root->val) return false;
        }
        return true;
    }
};
// inorder traversal with stack
class Solution01 {
public:
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // inorder traverse the BST
        stack<TreeNode*> inorder_stack;
        TreeNode *current = root, *previous = NULL;
        while (!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current = current->left;
            } else {
                current = inorder_stack.top();
                inorder_stack.pop();
                if (previous && previous->val >= current->val) return false;
                previous = current;
                current = current->right;
            }
        }
        return true;
    }
};
// Morris inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // inorder traverse the BST
        // Morris traversal
        TreeNode *current = root, *previous = NULL;
        while (current) {
            if (current->left) {
                TreeNode *left = current->left;
                while (left->right && left->right != current) left = left->right;
                if (!left->right) {
                    left->right = current;
                    current = current->left;
                } else {
                    left->right = NULL;
                    if (previous && previous->val >= current->val) return false;
                    previous = current;
                    current = current->right;
                }
            } else {
                if (previous && previous->val >= current->val) return false;
                previous = current;
                current = current->right;
            }
        }
        return true;
    }
};