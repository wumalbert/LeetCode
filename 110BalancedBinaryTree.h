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
private:
    bool isBalanced(TreeNode *root, int &depth)
    {
        if (!root)
        {
            depth = 0;
            return true;
        }
        else
        {
            int leftDepth = 0, rightDepth = 0;
            if (!isBalanced(root->left, leftDepth)) return false;
            if (!isBalanced(root->right, rightDepth)) return false;
            if (abs(leftDepth-rightDepth) > 1) return false;
            
            depth = max(leftDepth, rightDepth) + 1;
            return true;
        }
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth = 0;
        return isBalanced(root, depth);
    }
};