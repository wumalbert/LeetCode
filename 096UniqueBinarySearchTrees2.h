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
    vector<TreeNode*> generateTreesRecursive(int start, int end)
    {
        vector<TreeNode*> trees;
        
        if (start > end)
        {
            trees.push_back(NULL);
            return trees;
        }
        // the root node can be anyone between start and end 
        for (int i = start; i <= end; ++i)
        {   
            // the left tree [start, i-1]
            vector<TreeNode*> lefts = generateTreesRecursive(start, i-1);
            // the right tree [i+1, end]
            vector<TreeNode*> rights = generateTreesRecursive(i+1, end);
            
            for (vector<TreeNode*>::iterator left = lefts.begin(); left != lefts.end(); ++left)
                for (vector<TreeNode*>::iterator right = rights.begin(); right != rights.end(); ++right)
                {
                    // the root i
                    TreeNode *root = new TreeNode(i);
                    root->left = *left;
                    root->right = *right;
                    trees.push_back(root);
                }
        }
        
        return trees;
    }
    
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generateTreesRecursive(1, n);
    }
};