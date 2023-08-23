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

 //                   1                 // 1
 //               2       3             // 2
 //          4       5 6       7        // 3
 // [1, [2, 3], [4, 5, 6, 7]]

 //                   1
 //               2       3
 //          4      5         7
 //             4          10
 // [1, [2, 3], [4, 5, 7, 4, 10]]

class Solution {
public:
// complexity time: O(n), where n - nodes count
// complexity memory: O(h), where h - depth, if list then O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        // return preorderBase(root);
        return queueWay(root);
    }

private:
    vector<vector<int>> preorderBase(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> result(1);
        size_t level = 0u;
        result[level].push_back(root->val);
        preorder(root->left, level + 1, result);
        preorder(root->right, level + 1, result);
        return result;
    }

    void preorder(TreeNode *const root, size_t level, vector<vector<int>> &result) {
        if (!root) { return; }
        
        if (result.size() == level) {
            result.push_back({});
        }
        result[level].push_back(root->val);
        preorder(root->left, level + 1, result);
        preorder(root->right, level + 1, result);
    }

    vector<vector<int>> queueWay(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> result(1);
        queue<pair<TreeNode*, int>> nodes; // node + level
        nodes.push({root, 0u});
        while (!nodes.empty()) {
            auto [node, level] = nodes.front();
            nodes.pop();
            if (!node) {
                continue;
            }
            if (result.size() == level) {
                result.push_back({});
            }
            result[level].push_back(node->val);
            nodes.push({node->left, level + 1});
            nodes.push({node->right, level + 1});
        }
        return result;
    }
};