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
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        int path_sum;
        return dfs(root, path_sum);
    }
private:
    int dfs(TreeNode *root, int &max_path) {
        if (!root->left && !root->right) {
            max_path = root->val;
            return max_path;
        }
        int left, right, left_max, right_max;
        left_max = right_max = left = right = numeric_limits<int>::min();
        if (root->left) left_max = dfs(root->left, left);
        else left = 0; 
        if (root->right) right_max = dfs(root->right, right);
        else right = 0;
        max_path = root->val;
        if (left + root->val > max_path) max_path = left + root->val;
        if (right + root->val > max_path) max_path = right + root->val;
        int ret = max(left_max, right_max);
        if (left + right + root->val > ret) ret = left + right + root->val;
        if (max_path > ret) ret = max_path;
        return ret;
    }
};
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int path_sum;
        return dfs(root, path_sum);
    }
private:
    int dfs(TreeNode *root, int &max_path) {
        if (!root) {
            max_path = numeric_limits<int>::min();
            return max_path;
        }
        int left, right;
        int ret = max(dfs(root->left, left), dfs(root->right, right));
        ret = max(ret, root->val + (left > 0 ? left : 0) + (right > 0 ? right : 0));
        max_path = max(0, max(left, right)) + root->val;
        return ret;
    }
};