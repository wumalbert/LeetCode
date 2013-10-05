/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        dfs(root, 0, ret);
        return ret;
    }
private:
    void dfs(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (level >= ans.size()) ans.push_back(vector<int>());
        ans[level].push_back(root->val);
        if (root->left) dfs(root->left, level+1, ans);
        if (root->right) dfs(root->right, level+1, ans);
    }
};
// BFS
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        ret.push_back(vector<int>());
        int number_current_level = 1, number_next_level = 0;
        while (!node_queue.empty()) {
            TreeNode *current = node_queue.front();
            node_queue.pop();
            --number_current_level;
            ret.back().push_back(current->val);
            if (current->left) {
                node_queue.push(current->left);
                ++number_next_level;
            }
            if (current->right) {
                node_queue.push(current->right);
                ++number_next_level;
            }
            if (!number_current_level) {
                number_current_level = number_next_level;
                number_next_level = 0;
                if (number_current_level) ret.push_back(vector<int>());
            }
        }
        return ret;
    }
};