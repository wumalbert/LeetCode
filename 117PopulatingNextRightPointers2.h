/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        TreeLinkNode *current = root;
        // level order traversal
        while (current)
        {
            TreeLinkNode *previous = NULL, *next = NULL;
            
            // traversal the nodes in this level
            for (; current; current = current->next)
            {
                // the first node in the next level
                if (!next) next = current->left ? current->left : current->right;
                
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
            
            // to traversal the next level
            current = next;
        }
    }
};