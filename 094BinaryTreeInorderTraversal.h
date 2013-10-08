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
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
private:
    void dfs(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        stack<TreeNode*> inorder_stack;
        TreeNode *current = root;
        while (!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current = current->left;
            } else {
                current = inorder_stack.top();
                inorder_stack.pop();
                ret.push_back(current->val);
                current = current->right;
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
        TreeNode *current = root;
        while (current) {
            if (current->left) {
                TreeNode *node = current->left;
                while (node->right && node->right != current) node = node->right;
                if (!node->right) {
                    node->right = current;
                    current = current->left;
                } else {
                    ret.push_back(current->val);
                    node->right = NULL;
                    current = current->right;
                }
            } else {
                ret.push_back(current->val);
                current = current->right;
            }
        }
        return ret;
    }
};