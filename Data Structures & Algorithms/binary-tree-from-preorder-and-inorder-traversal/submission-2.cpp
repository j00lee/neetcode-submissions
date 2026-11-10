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
    int pre_idx = 0;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // USE dfs
        // build m
        map<int,int> m;
        for (int i = 0; i < inorder.size(); i++) {
            m[inorder[i]] = i;
        }

        return buildDFS(preorder, inorder, {0,preorder.size()-1}, m);
    }

    TreeNode* buildDFS(vector<int>& preorder, vector<int>& inorder, pair<int,int> inwindow, map<int,int> m) {
        int l = inwindow.first;
        int r = inwindow.second;

        // check valid
        if (l > r) {
            return nullptr;
        }

        // build node
        TreeNode* root = new TreeNode(preorder[pre_idx]);
        pre_idx++;
        int pivot = m[root->val];
        pair<int,int> leftWindow = {l,pivot-1};
        pair<int,int> rightWindow = {pivot+1,r};
        root->left = buildDFS(preorder, inorder, leftWindow, m);
        root->right = buildDFS(preorder, inorder, rightWindow, m);
        return root;
    }
};
