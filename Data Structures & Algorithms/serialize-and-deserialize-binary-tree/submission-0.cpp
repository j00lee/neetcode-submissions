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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // four chars per node
        // we shift all numbers up by 1000 
        string res = "";
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* first = q.front();
            q.pop();
            // add this node to string
            if (!first) {
                res += "null";
            } else {
                res += to_string(first->val+1000);
                q.push(first->left);
                q.push(first->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;

        vector<int> vals = getVals(data);
        TreeNode* tree = new TreeNode(vals[0]);
        int idx = 1;
        queue<TreeNode*> q;
        q.push(tree);
        while (!q.empty()) {
            cerr << "idx is " << idx << "\n";
            TreeNode* parent = q.front();
            q.pop();

            if (vals[idx] != -2000) {
                // make a node for this val
                TreeNode* left = new TreeNode(vals[idx]);
                parent->left = left;
                q.push(left);
            }
            if (vals[idx+1] != -2000) {
                // make a node for this val
                TreeNode* right = new TreeNode(vals[idx+1]);
                parent->right = right;
                q.push(right);
            }

            idx += 2;
        }
        return tree;
    }

private: 
    vector<int> getVals(string data) {
        vector<int> vals;
        for (int i = 0; i < data.size(); i+=4) {
            string substring = data.substr(i,4);
            if (substring == "null") {
                vals.push_back(-2000);
            } else {
                vals.push_back(stoi(substring)-1000);
            }
        }
        return vals;
    }
};
