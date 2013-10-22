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
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        queue<TreeNode*> left_queue, right_queue;
        left_queue.push(root->left);
        right_queue.push(root->right);
        while (!left_queue.empty() && !right_queue.empty()) {
            TreeNode *left = left_queue.front(), *right = right_queue.front();
            left_queue.pop();
            right_queue.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            left_queue.push(left->left);
            left_queue.push(left->right);
            right_queue.push(right->right);
            right_queue.push(right->left);
        }
        return true;
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        stack<TreeNode*> left_stack, right_stack;
        left_stack.push(root->left);
        right_stack.push(root->right);
        while (!left_stack.empty() && !right_stack.empty()) {
            TreeNode *left = left_stack.top(), *right = right_stack.top();
            left_stack.pop();
            right_stack.pop();
            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            left_stack.push(left->left);
            left_stack.push(left->right);
            right_stack.push(right->right);
            right_stack.push(right->left);
        }
        return true;
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return true;
        vector<TreeNode*> layer[2];
        layer[0].push_back(root);
        int current = 0;
        while (!layer[current].empty()) {
            layer[1-current].clear();
            for (vector<TreeNode*>::iterator i = layer[current].begin(); i != layer[current].end(); ++i) {
                if(!*i) continue;
                layer[1-current].push_back((*i)->left);
                layer[1-current].push_back((*i)->right);
            }
            for (vector<TreeNode*>::iterator i = layer[1-current].begin(), j = layer[1-current].end()-1; i < j; ++i, --j) {
                if (!*i && !*j) continue;
                if (!*i || !*j || (*i)->val != (*j)->val) return false;
            }
            current = 1-current;
        }
        return true;
    }
};