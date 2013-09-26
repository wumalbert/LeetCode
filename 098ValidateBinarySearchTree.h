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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        
        if (!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        
        // the largest node (most right node) of the left tree
        if (root->left)
        {
            TreeNode *node = root->left;
            while (node->right)
            {
                node = node->right;
            }
            if (node->val >= root->val) return false;
        }
        
        // the smallest node (most left node) of the right tree
        if (root->right)
        {
            TreeNode *node = root->right;
            while (node->left)
            {
                node = node->left;
            }
            if (node->val <= root->val) return false;
        }
        
        return true;
    }
};