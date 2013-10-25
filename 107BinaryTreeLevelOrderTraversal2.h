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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode *> level_queue;
        level_queue.push(root);
        ret.push_back(vector<int>());
        int nodes_current_level = 1, nodes_next_level = 0;
        while (!level_queue.empty()) {
            TreeNode *node = level_queue.front();
            level_queue.pop();
            --nodes_current_level;
            ret[0].push_back(node->val);
            if (node->left) {
                level_queue.push(node->left);
                ++nodes_next_level;
            }
            if (node->right) {
                level_queue.push(node->right);
                ++nodes_next_level;
            }
            if (0 == nodes_current_level) {
                if (nodes_next_level > 0) ret.insert(ret.begin(), vector<int>());
                nodes_current_level = nodes_next_level;
                nodes_next_level = 0;
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        dfs(root, 0, ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    void dfs(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (level >= ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[level].push_back(root->val);
        if (root->left) dfs(root->left, level+1, ans);
        if (root->right) dfs(root->right, level+1, ans);
    }
};