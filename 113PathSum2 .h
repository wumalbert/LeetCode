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
    void pathSum(TreeNode *root, int sum, vector<int> path, vector<vector<int> > &ans)
    {
        if (!root->left && !root->right && root->val == sum)
        {
            path.push_back(root->val);
            ans.push_back(path);
            return;
        }
        if (!root->left && !root->right) return;
        
        path.push_back(root->val);
        
        if (root->left) pathSum(root->left, sum-root->val, path, ans);
        if (root->right) pathSum(root->right, sum-root->val, path, ans);
    }
    
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (!root) return ret;
        
        vector<int> path;
        pathSum(root, sum, path, ret);
        
        return ret;
    }
};