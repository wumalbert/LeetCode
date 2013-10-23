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
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int depth = 0;
        return dfs(root, depth);
    }
private:
    bool dfs(TreeNode *root, int &depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int left_depth = 0, right_depth = 0;
        bool ret;
        if (dfs(root->left, left_depth) && 
            dfs(root->right, right_depth) && 
            left_depth - right_depth <= 1 && 
            left_depth - right_depth >= -1)
                ret = true;
        else ret = false;
        depth = max(left_depth, right_depth) + 1;
        return ret;
    }
};
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int depth = getDepth(root);
        return depth >= 0;
    }
private:
    int getDepth(TreeNode *root) {
        if (!root) return 0;
        int left_depth = getDepth(root->left);
        if (left_depth < 0) return -1;
        int right_depth = getDepth(root->right);
        if (right_depth < 0) return -1;
        if (left_depth - right_depth < -1 || left_depth - right_depth > 1) return -1;
        return max(left_depth, right_depth) + 1;
    }
};