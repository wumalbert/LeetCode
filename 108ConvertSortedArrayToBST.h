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
    TreeNode *sortedArrayToBST(const vector<int>& num, int begin, int end)
    {
        if (begin >= end) return NULL;
        
        int middle = begin + (end-1-begin)/2;
        TreeNode *root = new TreeNode(num[middle]);
        root->left = sortedArrayToBST(num, begin, middle);
        root->right = sortedArrayToBST(num, middle+1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num, 0, num.size());
    }
};