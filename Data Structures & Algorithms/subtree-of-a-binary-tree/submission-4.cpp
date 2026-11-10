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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> tree = {};
        vector<int> sub = {};
        
        serializeTree(root, tree);
        serializeTree(subRoot, sub);
        printlst(tree);
        printlst(sub);
        if (tree.size() < sub.size()) {
            return false;
        }

        for (int i = 0; i < tree.size(); i++) {
            bool match = true;
            for (int j = 0; j < sub.size(); j++) {
                if (tree[i+j] != sub[j]) {
                    match = false;
                }
            }
            if (match) {
                return true;
            }
        }
        return false;
    }

    void serializeTree(TreeNode* root, vector<int>& lst) {
        if (!root) {
            lst.push_back(-101);
            return;
        } 
        lst.push_back(root->val);
        serializeTree(root->left, lst);
        serializeTree(root->right, lst);
    }

    void printlst(vector<int>& lst) {
        printf("[");
        for (int num: lst) {
            printf("%d, ", num);
        }
        printf("]\n");
    }
};
