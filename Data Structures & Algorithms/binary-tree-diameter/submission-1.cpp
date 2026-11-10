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
    int diameterOfBinaryTree(TreeNode* root) {
        // Hypothesis: the farthest two nodes must be root or leaf nodes
        // the diameter of a subtree is the sum of the depth of left and right + 1
        int diameter = 0;
        helper(root, diameter);
        return diameter;
    }

    int helper(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int lheight = helper(root->left, diameter);
        int rheight = helper(root->right, diameter);
        int curr_diameter = lheight + rheight;
        printf("curr_diameter: %d\n", curr_diameter);
        if (curr_diameter > diameter) {
            diameter = curr_diameter;
        }
        return 1+max(lheight, rheight);
    }
};
