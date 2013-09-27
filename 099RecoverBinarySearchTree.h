/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution001 {
private:
    void inorderTraversal(TreeNode *root, TreeNode* &previous, TreeNode* &n1, TreeNode* &n2)
    {
        if (!root) return;
        
        inorderTraversal(root->left, previous, n1, n2);
        
        if (previous && previous->val > root->val)
        {
            n2 = root;
            if (!n1) n1 = previous;
        }
        
        previous = root;
        inorderTraversal(root->right, previous, n1, n2);
    }
    
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root) return;
        
        TreeNode *previous = NULL;
        TreeNode *n1 = NULL, *n2 = NULL;
        
        inorderTraversal(root, previous, n1, n2);
        
        if (n1 != n2)
        {
            n1->val = n1->val ^ n2->val;
            n2->val = n1->val ^ n2->val;
            n1->val = n1->val ^ n2->val;
        }
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // inorder morris traversal
        TreeNode *current = root, *previous = NULL;
        TreeNode *n1 = NULL, *n2 = NULL;
        
        while (current)
        {
            if (!current->left)
            {
                // the leaf node
                if (previous && previous->val > current->val)
                {
                    n2 = current;
                    if (!n1) n1 = previous;
                }
                previous = current;
                current = current->right;
            }
            else
            {
                // find the previous node in the inorder traversal sequence
                TreeNode* t = current->left;
                while (t->right && t->right != current)
                {
                    t = t->right;
                }
                if (!t->right) // build the thread link
                {
                    t->right = current;
                    current = current->left;
                }
                else // cancel the thread link
                {
                    t->right = NULL;
                    if (previous->val > current->val)
                    {
                        n2 = current;
                        if (!n1) n1 = previous;
                    }
                    previous = current;
                    current = current->right;
                }
            }
        }
        
        if (n1 != n2)
        {
            n1->val = n1->val ^ n2->val;
            n2->val = n1->val ^ n2->val;
            n1->val = n1->val ^ n2->val;
        }
    }
};