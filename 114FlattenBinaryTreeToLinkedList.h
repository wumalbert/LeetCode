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
    // return the last node of the preorder traversal
    TreeNode* flattenRecursive(TreeNode *root)
    {
        TreeNode *last = root;
        if (!root->left && !root->right) return last;
        
        TreeNode *right = root->right;
        if (root->left)
        {
            last = flattenRecursive(root->left);
            root->right = root->left;
            root->left = NULL;
        }
        if (right)
        {
            TreeNode *t = flattenRecursive(right);
            last->right = right;
            last = t;
        }
        
        return last;
    }
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        
        flattenRecursive(root);
    }
};