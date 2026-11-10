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
    void printStack(stack<pair<TreeNode*,int>> st) {
        printf("[");
        while (!st.empty()) {
            auto [node, max] = st.top();
            st.pop();
            printf("{%d, %d}, ", node->val, max);
        }
        printf("]");
    }

    int goodNodes(TreeNode* root) {
        // dfs
        // want to keep track of the largest val seen so far
        stack<pair<TreeNode*, int>> st;
        st.push({root, root->val});
        int count = 0;
        while (!st.empty()) {
            printStack(st);
            printf(" count: %d\n", count);
            auto [node, max] = st.top();
            st.pop();
            int val = node->val;
            if (val >= max) {
                count++;
            }
            if (node->left) st.push({node->left, val > max ? val : max});
            if (node->right) st.push({node->right, val > max ? val : max});
        }
        return count;
    }
};
