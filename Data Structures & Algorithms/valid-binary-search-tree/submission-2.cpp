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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        pair<int,int> res = isValidBSThelper(root);
        return res.first <= res.second;
    }

    pair<int,int> isValidBSThelper(TreeNode* root) {
        // check values of left and right children
        // check if left and right children are also BST
        printf("node: %d\n", root->val);
        int min = root->val;
        int max = root->val;
        if (root->left) {
            if (root->left->val >= root->val) return {0,-1};
            auto [minleft, maxleft] = isValidBSThelper(root->left);
            if (maxleft >= root->val or minleft > maxleft) return {0,-1};
            min = minleft;
        }
        if (root->right) {
            if (root->right->val <= root->val) return {0,-1};
            auto [minright, maxright] = isValidBSThelper(root->right);
            if (minright <= root->val or minright > minright) return {0,-1};
            max = maxright;
        }
        return {min,max};
    }
};
