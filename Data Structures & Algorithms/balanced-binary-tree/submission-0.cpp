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
    bool isBalanced(TreeNode* root) {
        // base case
        return (height(root) != -1 ? true : false);
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        printf("left height: %d, right height: %d\n", lheight, rheight);
        if (lheight == -1 or rheight == -1) {
            return -1;
        } else if (abs(lheight - rheight) > 1) {
            return -1;
        }
        return 1+max(lheight, rheight);
    }
};
