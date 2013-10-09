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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        if (!root->left && !root->right) return false;
        if (root->left && hasPathSum(root->left, sum-root->val)) return true;
        if (root->right && hasPathSum(root->right, sum-root->val)) return true;
        return false;
    }
};
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return false;
        stack<TreeNode*> inorder_stack;
        stack<int> sum_stack;
        TreeNode *current = root;
        int current_sum = 0;
        while (!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current_sum += current->val;
                sum_stack.push(current_sum);
                current = current->left;
            } else {
                current = inorder_stack.top();
                inorder_stack.pop();
                current_sum = sum_stack.top();
                sum_stack.pop();
                if (!current->left && !current->right && current_sum == sum) return true;
                current = current->right;
            }
        }
        return false;
    }
};