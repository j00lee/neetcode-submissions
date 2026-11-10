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
    vector<int> rightSideView(TreeNode* root) {
        // BFS
        // the rightmost node on every layer is visible
        vector<int> res = {};
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            printQueue(q);
            TreeNode* right = q.back();
            res.push_back(right->val);
            printf("rightmost: %d\n", right->val);
            // replace this layer with next layer
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }

    void printQueue(queue<TreeNode*> q) {
        printf("[");
        int size = q.size();
        for (int i = 0; i < size; i++) {
            printf("%d, ", q.front()->val);
            q.pop();
        }
        printf("]\n");
    }
};
