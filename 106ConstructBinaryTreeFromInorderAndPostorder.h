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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode *buildTree(vector<int> &inorder, int begin1, int end1, 
                        vector<int> &postorder, int begin2, int end2) {
        if (begin1 >= end1 || begin2 >= end2) return NULL;
        int i = 0;
        for (i = begin1; i < end1 && inorder[i] != postorder[end2-1]; ++i);
        int t = begin2 + (i-begin1);
        TreeNode *root = new TreeNode(inorder[i]);
        root->left = buildTree(inorder, begin1, i, postorder, begin2, t);
        root->right = buildTree(inorder, i+1, end1, postorder, t, end2-1);
        return root;
    }
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (inorder.empty() || inorder.size() != postorder.size()) return NULL;
        stack<TreeNode*> root_stack;
        TreeNode *root = new TreeNode(postorder.back()), *current = root;
        root_stack.push(root);
        int in_index = inorder.size()-1, post_index = postorder.size()-2;
        while (post_index >= 0) {
            bool poped = false;
            while (!root_stack.empty() && root_stack.top()->val == inorder[in_index]) {
                current = root_stack.top();
                root_stack.pop();
                --in_index;
                poped = true;
            }
            if (poped) {
                TreeNode *left = new TreeNode(postorder[post_index--]);
                root_stack.push(left);
                current->left = left;
                current = left;
            } else {
                TreeNode *right = new TreeNode(postorder[post_index--]);
                root_stack.push(right);
                current->right = right;
                current = right;
            }
        }
        return root;
    }
};