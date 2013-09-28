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
    TreeNode *buildTree(vector<int>& preorder, int begin1, int end1, 
        vector<int>& inorder, int begin2, int end2)
    {
        if (begin1 >= end1 || begin2 >= end2) return NULL;
        
        int i;
        for (i = begin2; i < end2 && inorder[i] != preorder[begin1]; ++i);
        int t = 1+begin1+(i-begin2);
        
        TreeNode* root = new TreeNode(preorder[begin1]);
        root->left = buildTree(preorder, begin1+1, t, inorder, begin2, i);
        root->right = buildTree(preorder, t, end1, inorder, i+1, end2);
        
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
            return NULL;
        
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};