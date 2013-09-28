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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        // use breadth first search
        queue<pair<TreeNode*, int> > levelQueue;
        levelQueue.push(make_pair(root, 1));
        
        while (!levelQueue.empty())
        {
            pair<TreeNode*, int> node = levelQueue.front();
            levelQueue.pop();
            
            if (!node.first->left && !node.first->right) return node.second;
            
            if (node.first->left) levelQueue.push(make_pair(node.first->left, node.second+1));
            if (node.first->right) levelQueue.push(make_pair(node.first->right, node.second+1));
        }
    }
};