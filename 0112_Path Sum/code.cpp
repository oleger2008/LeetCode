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
private:
    struct NodeToSum {
        TreeNode *node = nullptr;
        int sum = 0;
    };

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        stack<NodeToSum> nodesToSums;
        nodesToSums.push(NodeToSum{root, targetSum});
        while (!nodesToSums.empty()) {
            const auto [node, sum] = nodesToSums.top();
            nodesToSums.pop();
            const int rest = sum - node->val;
            if ((!node->left) && (!node->right) && (rest == 0)) {
                return true;
            }
            if (node->left) {
                nodesToSums.push(NodeToSum{node->left, rest});
            }
            if (node->right) {
                nodesToSums.push(NodeToSum{node->right, rest});
            }
        }
        return false;
    }
};