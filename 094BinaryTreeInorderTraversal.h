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
    vector<int> inorderTraversal01(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        
        stack<TreeNode*> inorderStack;
        
        TreeNode *node = root;
        while (node)
        {
            inorderStack.push(node);
            node = node->left;
        }
        
        while (!inorderStack.empty())
        {
            TreeNode *node = inorderStack.top();
            inorderStack.pop();
            ret.push_back(node->val);
            
            if (node->right)
            {
                node = node->right;
                while (node)
                {
                    inorderStack.push(node);
                    node = node->left;
                }
            }
        }
        
        return ret;
    }

    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;

        TreeNode *current = root;
        stack<TreeNode*> inorderStack;

        while (!inorderStack.empty() || current)
        {
            if (current)
            {
                inorderStack.push(current);
                current = current->left;
            }
            else
            {
                current = inorderStack.top();
                inorderStack.pop();
                ret.push_back(current->val);
                current = current->right;
            }
        }

        return ret;
    }
};