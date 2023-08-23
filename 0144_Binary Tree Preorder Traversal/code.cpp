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

//                    1
//                  2   3
//                4  5 6  7

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> result;
        // recursive(root, result);
        stacked(root, result);
        return result;
    }

private:
    void recursive(TreeNode* root, vector<int> &result) {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        recursive(root->left, result);
        recursive(root->right, result);
    }

    void stacked(TreeNode* root, vector<int> &result) {
        if (!root) {
            return;
        }
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto *node = nodes.top();
            nodes.pop();
            if (!node) {
                continue;
            }

            result.push_back(node->val);
            nodes.push(node->right);
            nodes.push(node->left);
        }
    }

};