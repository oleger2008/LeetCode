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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> nodes;
        nodes.push(root);
        int depth = 0;
        while (!nodes.empty()) {
            ++depth;
            const auto size = nodes.size();
            for (size_t i = 0u; i < size; ++i) {
                const auto *node = nodes.front();
                nodes.pop();
                bool hasNoChildren = true;
                if (node->left) {
                    nodes.push(node->left);
                    hasNoChildren = false;
                }
                if (node->right) {
                    nodes.push(node->right);
                    hasNoChildren = false;
                }
                if (hasNoChildren) {
                    return depth;
                }
            }
        }
        return depth;
    }
};