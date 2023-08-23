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

// target 8
 //                  10
 //          5                 -3
 //    3          2                  11
 // 3     -2           1
 // [5, 3], [5, 2, 1], [-3, 11] = 3

// target 3
// 1 - 2 - 3 - 4 - 5
// [1-2], [3] = 2

// target -1
//                  1
//        -2                -3
//    1       3        -2
// -1
// [1, -2], [1, -2, 1, -1], [-2, 1], [-1] = 4

// target 1000
// 10^9 - 10^9 - ... - 10^9
// 0 , its stress test

// complexity:
// time: O(2n) - n - nodes count
// memory: O(h) where h - depth of tree, if list then O(n)
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int result = 0;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto *node = nodes.top();
            nodes.pop();
            if (!node) {
                continue;
            }
            recursive(node, targetSum, 0, result);
            nodes.push(node->left);
            nodes.push(node->right);
        }
        return result;
    }

private:
    void recursive(TreeNode* root, int targetSum, int64_t curSum, int &result) {
        if (!root) return;

        curSum += root->val;
        if (targetSum == curSum) {
            ++result;
        } 
        recursive(root->left, targetSum, curSum, result);
        recursive(root->right, targetSum, curSum, result);
    }
};