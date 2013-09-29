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
    void maxPathSum(TreeNode *root, int &m1, int &m2)
    {
        if (!root->left && !root->right)
        {
            m1 = m2 = root->val;
            return;
        }
        int l1, l2, r1, r2;
        l1 = l2 = r1 = r2 = numeric_limits<int>::min();
        if(root->left) maxPathSum(root->left, l1, l2);
        if(root->right) maxPathSum(root->right, r1, r2);
        
        int t = max(l2, r2);
        if (t <= 0) m2 = root->val;
        else m2 = t + root->val;
        
        m1 = max(l1, r1);
        if (root->left && root->right) t = max(t, l2+r2);
        if (t <= 0) m1 = max(m1, root->val);
        else m1 = max(m1, t + root->val);
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return numeric_limits<int>::min();
        
        int m1, m2;
        maxPathSum(root, m1, m2);
        return m1;
    }
};