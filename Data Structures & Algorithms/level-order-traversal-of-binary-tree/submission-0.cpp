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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // BFS
        map<int,vector<int>> m;
        if (!root) {
            return {};
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            // Add node to appropriate level
            if (m.find(level) == m.end()) {
                m[level] = {};
            }
            m[level].push_back(node->val);
            // Add children of node to queue
            if (node->left) q.push({node->left, level+1});
            if (node->right) q.push({node->right, level+1});
        }

        // build vector from map
        vector<vector<int>> res = {};
        for (auto& [level, lst]: m) {
            res.push_back(lst);
        }
        return res;
    }
};
