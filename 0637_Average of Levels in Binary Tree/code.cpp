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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> nodes;
        nodes.push(root);
        vector<double> result;
        while (!nodes.empty()) {
            const size_t size = nodes.size();
            double sum = 0.;
            for (size_t i = 0u; i < size; ++i) {
                const auto *node = nodes.front();
                nodes.pop();
                sum += static_cast<double>(node->val);
                if (node->left != nullptr) {
                    nodes.push(node->left);
                }
                if (node->right != nullptr) {
                    nodes.push(node->right);
                }
            }
            result.push_back(sum / static_cast<double>(size));
        }
        return result;
    }
};