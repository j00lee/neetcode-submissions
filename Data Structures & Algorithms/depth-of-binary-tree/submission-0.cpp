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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int depth = 0;
        stack<pair<TreeNode*,int>> st;
        st.push(pair(root,0));
        while(!st.empty()) {
            auto [node, curr_depth] = st.top();
            st.pop();
            if (!node) {
                printf("reached end current depth: %d\n", curr_depth);
                depth = max(curr_depth, depth);
            } else {
                printf("node: %d, current depth: %d\n", node->val, curr_depth);
                st.push(pair(node->left, curr_depth+1));
                st.push(pair(node->right, curr_depth+1));
            }
        }
        return depth;
    }
};
