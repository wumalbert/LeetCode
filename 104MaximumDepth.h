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
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return 1 + max(left_depth, right_depth);
    }
};
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        stack<TreeNode *> preorder_stack;
        stack<int> depth_stack;
        preorder_stack.push(NULL);
        depth_stack.push(0);
        TreeNode *current = root;
        int current_depth = 1, max_depth = 0;
        while (!preorder_stack.empty() || current) {
            if (!current->left && !current->right && current_depth > max_depth) {
                max_depth = current_depth;
            } 
            if (current->right) {
                preorder_stack.push(current->right);
                depth_stack.push(current_depth+1);
            } 
            if (current->left) {
                current = current->left;
                ++current_depth;
            } else {
                current = preorder_stack.top();
                preorder_stack.pop();
                current_depth = depth_stack.top();
                depth_stack.pop();
            }
        }
        return max_depth;
    }
};
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        stack<TreeNode *> postorder_stack;
        postorder_stack.push(root);
        int max_depth = 0;
        TreeNode *previous = NULL, *current = NULL;
        while (!postorder_stack.empty()) {
            current = postorder_stack.top();
            if (!previous || previous->left == current || previous->right == current) {
                if (current->left) postorder_stack.push(current->left);
                else if (current->right) postorder_stack.push(current->right);
            } else if (current->left == previous) {
                if (current->right) postorder_stack.push(current->right);
            } else {
                postorder_stack.pop();
            }
            previous = current;
            if (postorder_stack.size() > max_depth) max_depth = postorder_stack.size();
        }
        return max_depth;
    }
};
class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int nodes_current_level = 1, nodes_next_level = 0, depth = 0;
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            --nodes_current_level;
            if (node->left) {
                node_queue.push(node->left);
                ++nodes_next_level;
            }
            if (node->right) {
                node_queue.push(node->right);
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