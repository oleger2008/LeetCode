// Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

//             1
//        2         3
//   4        5  6       7
// [4, 5, 2, 6, 7, 3, 1]

//             1
//        2         3
//   4
// [4, 2, 3, 1]

// empty: []
// single node: [1]

// nodes: [0, 100]
// nodes->val: [-100, 100]

//complexity:
// time: O(n)
// memory: O(n)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recursive(root, result);
        return result;
    }

private:
    void recursive(TreeNode* root, vector<int>& result) {
        if (!root) return;

        recursive(root->left, result);
        recursive(root->right, result);
        result.push_back(root->val);
    }
};