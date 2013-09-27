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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        
        if (!root) return ret;
        
        queue<pair<TreeNode*, int> > levelQueue;
        int last = -1;
        levelQueue.push(make_pair(root, 0));
        while (!levelQueue.empty())
        {
            pair<TreeNode*, int> node = levelQueue.front();
            levelQueue.pop();
            if (node.second != last)
            {
                ret.push_back(vector<int>(1, node.first->val));
                last = node.second;
            }
            else
            {
                ret[ret.size()-1].push_back(node.first->val);
            }
            
            if (node.first->left) levelQueue.push(make_pair(node.first->left, node.second+1));
            if (node.first->right) levelQueue.push(make_pair(node.first->right, node.second+1));
        }
        
        return ret;
    }
};