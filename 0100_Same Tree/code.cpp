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
    // my naive
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *> lhs;
        lhs.push(p);
        stack<TreeNode *> rhs;
        rhs.push(q);
        while (!lhs.empty() && !rhs.empty()) {
            auto *const first = lhs.top();
            lhs.pop();
            auto *const second = rhs.top();
            rhs.pop();

            if (!first && !second) {
                continue;
            }
            if (!first || !second) {
                return false;
            }
            
            if (first->val != second->val) {
                return false;
            }

            lhs.push(first->left);
            lhs.push(first->right);
            rhs.push(second->left);
            rhs.push(second->right);
        }

        return lhs.empty() && rhs.empty();
    }
};