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
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        // pretraverse the tree
        if(!p && !q) return true;
        if(!p || !q) return false;
        
        stack<TreeNode*> treeStack1, treeStack2;
        TreeNode *current1 = p, *current2 = q;
        while(!treeStack1.empty() || current1)
        {
            if (current1)
            {
                if(!current2 || current2->val != current1->val) return false;
                if(current1->right && current2->right)
                {
                    treeStack1.push(current1->right);
                    treeStack2.push(current2->right);
                }
                else if ((!current1->right && current2->right) || (current1->right && !current2->right)) return false;
                current1 = current1->left;
                current2 = current2->left;
            }
            else
            {
                if (current2 || treeStack2.empty()) return false;
                current1 = treeStack1.top();
                treeStack1.pop();
                current2 = treeStack2.top();
                treeStack2.pop();
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};