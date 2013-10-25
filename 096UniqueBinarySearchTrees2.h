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
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<TreeNode *> trees;
        dfs(1, n, trees);
        return trees;
    }
private:
    void dfs(int start, int end, vector<TreeNode *> &trees) {
        if (start > end) {
            trees.push_back(NULL);
        } else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode *> left_trees, right_trees;
                dfs(start, i-1, left_trees);
                dfs(i+1, end, right_trees);
                for (int l = 0; l < left_trees.size(); ++l) {
                    for (int r = 0; r < right_trees.size(); ++r) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_trees[l];
                        root->right = right_trees[r];
                        trees.push_back(root);
                    }
                }
            }
        }
    }
};
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<vector<TreeNode *> > > trees(n+2, vector<vector<TreeNode *> >(n+2, vector<TreeNode *>()));
        dfs(1, n, trees);
        return trees[1][n];
    }
private:
    void dfs(int start, int end, vector<vector<vector<TreeNode *> > > &trees) {
        if (!trees[start][end].empty()) return;
        if (start > end) {
            trees[start][end].push_back(NULL);
        } else {
            for (int i = start; i <= end; ++i) {
                dfs(start, i-1, trees);
                dfs(i+1, end, trees);
                for (int l = 0; l < trees[start][i-1].size(); ++l) {
                    for (int r = 0; r < trees[i+1][end].size(); ++r) {
                        TreeNode *root = new TreeNode(i);
                        root->left = trees[start][i-1][l];
                        root->right = trees[i+1][end][r];
                        trees[start][end].push_back(root);
                    }
                }
            }
        }
    }
};