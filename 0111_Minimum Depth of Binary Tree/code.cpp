// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest
// path from the root node down to the nearest leaf node.
// Note: A leaf is a node with no children.

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

//             3
//      9             20
//               15        7
//                  11
// anw: 2

// 1 - 2 - 3 - 4 - 5
// anw: 5

// nodes cout: [0, 10^5]
// node->val: [-1000, 1000]

// complexity:
// time: O(n)
// memory: O(n)

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int result = std::numeric_limits<int>::max();
        recursive(root, 0, result);
        return result + 1;
    }

private:
    void recursive(TreeNode* root, int curLvl, int &result) {
        if (!root) return;

        if (!root->left && !root->right ) {
            result = std::min(curLvl, result);
            return;
        }

        recursive(root->left, curLvl + 1, result);
        recursive(root->right, curLvl + 1, result);
    }

private:
    int queuBy(TreeNode* root) {
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