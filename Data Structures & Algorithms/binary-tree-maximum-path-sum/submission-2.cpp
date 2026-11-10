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
    int max = -2000;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max;
    }

    int dfs(TreeNode* root) {
        // Goal: O(n) time and O(n) space
        // max path which goes through this node is 
        // root->val + max(leftmax, rightmax, leftmax+rightmax)
        if (!root) return 0;

        int leftmax = dfs(root->left);
        int rightmax = dfs(root->right);
        int pathsum = root->val + std::max({leftmax,rightmax,0});
        max = std::max({pathsum, max, root->val+leftmax+rightmax});
        printf("pathsum: %d\n", pathsum);
        printf("current max: %d and node: %d\n", max, root->val);
        return pathsum;
    }
};
