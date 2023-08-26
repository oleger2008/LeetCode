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

// 1
//  \
//   2
//  /
// 3
// 1,3,2

//          1
//     2        3
//  4    5    6   7
// [4,2,5,1,6,3,7]
// -100 <= Node.val <= 100
// [0, 100] Nodes

// time: O(n), n - nodes count
// memory: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        // recursive(root, result);
        stackBy(root, result);
        return result;
    }

private:
    void recursive(TreeNode* root, vector<int> &result) {
        if (!root) return;

        recursive(root->left, result);
        result.push_back(root->val);
        recursive(root->right, result);
    }

    void stackBy(TreeNode* root, vector<int> &result) {
        if (!root) return;

        stack<TreeNode*> nodes;
        auto *curNode = root;
        while (true) {
            if (curNode) {
                nodes.push(curNode);
                curNode = curNode->left;
            } else if (nodes.empty()) {
                break;
            } else {
                auto *node = nodes.top();
                nodes.pop();
                result.push_back(node->val);
                curNode = node->right;
            }
        }
    }
};