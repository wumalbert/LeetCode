/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution01 {
private:
    // convert the [start, end) of the sorted array to BST
    TreeNode *sortedArrayToBST(const vector<int> &num, int start, int end)
    {
        if (start >= end) return NULL;
        int mid = start + ((end - 1 - start) >> 1);
        TreeNode *root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, start, mid);
        root->right = sortedArrayToBST(num, mid+1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num, 0, num.size()); 
    }
};

class Solution {
private:
    // convert the [start, end) of the sorted array to BST
    TreeNode *sortedArrayToBST(vector<int>::const_iterator begin, vector<int>::const_iterator end)
    {
        if (begin >= end) return NULL;
        vector<int>::const_iterator mid = begin + ((end - begin) >> 1);
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(begin, mid);
        root->right = sortedArrayToBST(mid+1, end);
        return root;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sortedArrayToBST(num.begin(), num.end()); 
    }
};