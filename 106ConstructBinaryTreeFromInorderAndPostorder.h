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
    TreeNode *buildTree(vector<int> &inorder, int begin1, int end1, 
        vector<int> &postorder, int begin2, int end2)
    {
        if (begin1 >= end1 || begin2 >= end2) return NULL;
        
        int i = 0;
        for (i = begin1; i < end1 && inorder[i] != postorder[end2-1]; ++i);
        int t = begin2 + (i-begin1);
        
        TreeNode *root = new TreeNode(inorder[i]);
        root->left = buildTree(inorder, begin1, i, postorder, begin2, t);
        root->right = buildTree(inorder, i+1, end1, postorder, t, end2-1);
        
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
            return NULL;
        
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};