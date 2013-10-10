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
        // Note: The Solution object is instantiated only once and is reused by each test case.
        TreeLinkNode *current_level = root, *next_level = new TreeLinkNode(0);
        while (current_level) {
            TreeLinkNode *tail = next_level;
            while (current_level) {
                if (current_level->left) {
                    tail->next = current_level->left;
                    tail = tail->next;
                }
                if (current_level->right) {
                    tail->next = current_level->right;
                    tail = tail->next;
                }
                current_level = current_level->next;
            }
            current_level = next_level->next;
            next_level->next = NULL;
        }
        delete next_level;
    }
};