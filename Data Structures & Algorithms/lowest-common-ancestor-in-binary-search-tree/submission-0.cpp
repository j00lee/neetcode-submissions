/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // lca is the first node at which p and q diverge
        int pal = p->val;
        int qal = q->val;

        TreeNode* curr = root;
        while (curr) {
            if (curr->val == pal or curr->val == qal) {
                return curr;
            } else if (pal < curr->val and qal > curr->val || pal > curr->val and qal < curr->val) {
                return curr;
            }
            if (pal < curr->val) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }
};
