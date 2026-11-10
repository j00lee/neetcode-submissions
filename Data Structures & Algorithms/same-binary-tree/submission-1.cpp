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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Iterative DFS
        stack<TreeNode*> stp;
        stack<TreeNode*> stq;

        if (p) {
            stp.push(p);
        }
        if (q) {
            stq.push(q);
        }

        while (!stp.empty() and !stq.empty()) {
            TreeNode* nodep = stp.top();
            TreeNode* nodeq = stq.top();
            stp.pop();
            stq.pop();
            if (!nodep and !nodeq) {
                continue;
            } else if (!nodep or !nodeq) {
                return false;
            }
            if (nodep->val != nodeq->val) {
                return false;
            }
            stp.push(nodep->left);
            stp.push(nodep->right);
            stq.push(nodeq->left);
            stq.push(nodeq->right);
        }
        if (!stp.empty() or !stq.empty()) {
            return false;
        }
        return true;
    }
};
