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
    int sumNumers(TreeNode *root, int &coef)
    {
        if (!root->left && !root->right)
        {
            coef = 1;
            return root->val;
        }
        int ret = 0;
        coef = 0;
        if (root->left)
        {
            int left;
            ret += sumNumers(root->left, left);
            coef += left * 10;
        }
        if (root->right)
        {
            int right;
            ret += sumNumers(root->right, right);
            coef += right * 10;
        }
        
        return ret + root->val * coef;
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return 0;
        
        int coef = 0;
        return sumNumers(root, coef);
    }
};