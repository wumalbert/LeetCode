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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
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
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (preorder.empty() || preorder.size() != inorder.size()) return NULL;
        stack<TreeNode*> root_stack;
        TreeNode *root = new TreeNode(preorder[0]), *current = root;
        root_stack.push(root);
        int pre_index = 1, in_index = 0;
        while (pre_index < preorder.length()) {
            bool poped = false;
            while (!root_stack.empty() && inorder[in_index] == root_stack.top()->val) {
                current = root_stack.top();
                root_stack.pop();
                ++in_index;
                poped = true;
            }
            if (poped) {
                TreeNode *right = new TreeNode(preorder[pre_index++]);
                root_stack.push(right);
                current->right = right;
                current = right;
            } else {
                TreeNode *left = new TreeNode(preorder[pre_index++]);
                root_stack.push(left);
                current->left = left;
                current = left;
            }
        }
        return root;
    }
};