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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        if (!root) return ret;
        queue<TreeNode*> nodes_queue;
        int nodes_current_level = 1, nodes_next_level = 0;
        bool forward = true; // the direction of the current level
        nodes_queue.push(root);
        ret.push_back(vector<int>());
        while (!nodes_queue.empty()) {
            TreeNode* node = nodes_queue.front();
            nodes_queue.pop();
            --nodes_current_level;
            if (forward) ret.back().push_back(node->val);
            else ret.back().insert(ret.back().begin(), node->val); 
            if (node->left) {
                nodes_queue.push(node->left);
                ++nodes_next_level;
            }
            if (node->right) {
                nodes_queue.push(node->right);
                ++nodes_next_level;
            }
            if (!nodes_current_level) {
                if (!nodes_queue.empty()) ret.push_back(vector<int>());
                forward = !forward;
                nodes_current_level = nodes_next_level;
                nodes_next_level = 0;
            }
        }
        return ret;
    }
};
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        dfs(root, 0, ret);
        return ret;
    }
    
private:
    void dfs(TreeNode *root, int level, vector<vector<int> > &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(vector<int>());
        if (level & 0x1) ans[level].insert(ans[level].begin(), root->val);
        else ans[level].push_back(root->val);
        dfs(root->left, level+1, ans);
        dfs(root->right, level+1, ans);
    }
};