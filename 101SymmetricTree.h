/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution01 {
private:
    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;
        
        return isSymmetric(root->left, root->right);
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return true;

        queue<TreeNode*> leftQueue;
        queue<TreeNode*> rightQueue;

        leftQueue.push(root->left);
        rightQueue.push(root->right);

        while (!leftQueue.empty() && !rightQueue.empty())
        {
            TreeNode* left = leftQueue.front();
            TreeNode* right = rightQueue.front();
            leftQueue.pop();
            rightQueue.pop();

            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;
            leftQueue.push(left->left);
            leftQueue.push(left->right);
            rightQueue.push(right->right);
            rightQueue.push(right->left);
        }
        return true;
    }
};