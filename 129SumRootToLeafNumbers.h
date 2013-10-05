/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive down to up
class Solution01 {
public:
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        int coef = 0;
        return dfs(root, coef);
    }
private:
    int dfs(TreeNode *root, int &coef) {
        if (!root->left && !root->right) {
            coef = 10;
            return root->val;
        }
        int sum = 0;
        int left_coef = 0, right_coef = 0;
        if (root->left) sum += dfs(root->left, left_coef);
        if (root->right) sum += dfs(root->right, right_coef);
        sum += root->val * (left_coef + right_coef);
        coef = (left_coef + right_coef) * 10;
        return sum;
    }
};
// recursive up to down
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode *root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
// iteration
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        int ret = 0;
        stack<TreeNode*> inorder_stack;
        stack<int> sum_stack;
        inorder_stack.push(root);
        sum_stack.push(root->val);
        while (!inorder_stack.empty()) {
            TreeNode *node = inorder_stack.top();
            int sum = sum_stack.top();
            inorder_stack.pop();
            sum_stack.pop();
            
            if (!node->left && !node->right) {
                ret += sum;
                continue;
            }
            
            if (node->right) {
                inorder_stack.push(node->right);
                sum_stack.push(sum * 10 + node->right->val);
            }
            if (node->left) {
                inorder_stack.push(node->left);
                sum_stack.push(sum * 10 + node->left->val);
            }
        }
        return ret;
    }
};