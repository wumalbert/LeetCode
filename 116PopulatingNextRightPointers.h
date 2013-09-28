/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution01 {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // morris traversal
        TreeLinkNode *current = root, *left = NULL, *right = NULL;
        
        while (current)
        {
            if (!current->left)
            {
                current = current->right;
            }
            else
            {
                left = current->left;
                right = current->right;
                left->next = right;
                while (left->right && left->right != current)
                {
                    left = left->right;
                    right = right->left;
                    left->next = right;
                }
                
                if (!left->right)
                {
                    left->right = current;
                    current = current->left;
                }
                else
                {
                    left->right = NULL;
                    current = current->right;
                }
            }
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeLinkNode *current = root;
        while (current)
        {
            // find the first node of the next level
            TreeLinkNode *next = current->left ? current->left : current->right;
            
            // traversal the nodes in the current level
            TreeLinkNode *previous = NULL;
            for (; current; current = current->next)
            {
                if (current->left)
                {
                    if (previous) previous->next = current->left;
                    previous = current->left;
                }
                if (current->right)
                {
                    if (previous) previous->next = current->right;
                    previous = current->right;
                }
            }
            
            current = next;
        }
    }
};