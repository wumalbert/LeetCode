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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ret = numeric_limits<int>::max();
        if (root->left) ret = min(ret, minDepth(root->left)+1);
        if (root->right) ret = min(ret, minDepth(root->right)+1);
        return ret;
    }
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        queue<TreeNode *> level_queue;
        level_queue.push(root);
        int nodes_current_level = 1, nodes_next_level = 0, depth = 1;
        while (!level_queue.empty()) {
            TreeNode *node = level_queue.front();
            level_queue.pop();
            --nodes_current_level;
            if (!node->left && !node->right) return depth;
            if (node->left) {
                level_queue.push(node->left);
                ++nodes_next_level;
            }
            if (node->right) {
                level_queue.push(node->right);
                ++nodes_next_level;
            }
            if (0 == nodes_current_level) {
                nodes_current_level = nodes_next_level;
                nodes_next_level = 0;
                ++depth;
            }
        }
        return depth;
    }
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        stack<TreeNode *> post_stack;
        post_stack.push(root);
        TreeNode *current = root, *previous = NULL;
        int depth = numeric_limits<int>::max();
        while (!post_stack.empty()) {
            current = post_stack.top();
            if (!previous || previous->left == current || previous->right == current) {
                if (current->left) post_stack.push(current->left);
                else if (current->right) post_stack.push(current->right);
            } else if (current->left == previous) {
                if (current->right) post_stack.push(current->right);
            } else {
                if (!current->left && !current->right && post_stack.size() < depth) 
                    depth = post_stack.size();
                post_stack.pop();
            }
            previous = current;
        }
        return depth;
    }
};