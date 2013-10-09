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
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution01 {
private:
    void pathSumRecursive(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &ans) {
        if(!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        sum -= root->val;
        if (root->left) pathSumRecursive(root->left, sum, path, ans);
        if (root->right) pathSumRecursive(root->right, sum, path, ans);
        path.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> path;
        vector<vector<int> > ret;
        pathSumRecursive(root, sum, path, ret);
        return ret;
    }
};

class Solution {
public:
    // iterate to solve the problem
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if (!root) return ret;
        stack<TreeNode*> postStack; // post traversal
        stack<bool> postMask; // the mask of post traversal
        vector<int> path; // the presum of the post traversal 
        path.push_back(0);
        TreeNode *current = root;
        while (!postStack.empty() || current) {
            if (current) {
                postStack.push(current);
                postMask.push(false);
                path.push_back(path.back() + current->val);
                current = current->left;
            } else {
                current = postStack.top();
                if (!postMask.top()) {
                    postMask.top() = true;
                    current = current->right;
                } else {
                    if (!current->left && !current->right && path.back() == sum)
                    {
                        vector<int> v;
                        for (vector<int>::iterator i = path.begin(); i+1 != path.end(); ++i)
                            v.push_back(*(i+1) - *i);
                        ret.push_back(v);
                    }
                    postStack.pop();
                    postMask.pop();
                    path.pop_back();
                    current = NULL;
                }
            }
        }
        
        return ret;
    }
};