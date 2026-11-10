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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }

        // Use a stack
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            // pop from stack
            TreeNode* node = st.top();
            st.pop();
            // switch its left and right children
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            node->left = right;
            node->right = left;
            // push left and right children to stack
            if (left) {
                st.push(left);
            }
            if (right) {
                st.push(right);
            }
        }
        return root;
    }
};
