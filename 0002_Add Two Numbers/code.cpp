// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

// list.size: [1..100]
// node.val: [0..9]
// no leading zeros

// 1025
//   66
// 1091

// ans
// i
// 1
// f
// 5 -> 2 -> 0 -> 1
// s
// 6 -> 6
// sum = 11
// vUme = sum / 10 = 1
// i = sum % 10

// ans
//      i
// 1 -> 9
//      f
// 5 -> 2 -> 0 -> 1
//      s
// 6 -> 6
// sum = 2 + 6 + vUme = 9
// vUme = sum / 10 = 0
// i = sum % 10 = 9

// ans
//           i
// 1 -> 9 -> 0
//           f
// 5 -> 2 -> 0 -> 1
//           s
// 6 -> 6 -> 0 -> 0
// sum = 0 + 0 + vUme = 0
// vUme = sum / 10 = 0
// i = sum % 10 = 0

// ans
//           i
// 1 -> 9 -> 0
//                f
// 5 -> 2 -> 0 -> 1
//                s
// 6 -> 6 -> 0 -> 0
// sum = 0 + 0 + vUme = 0
// vUme = sum / 10 = 0
// i = sum % 10 = 0

// if in end vUme != 0 then make one more node

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution { // time: O(n + m), mem: O(1)
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //                cur
        // 2 -> 0 -> 3 -> 0
        //                l1
        // 1 -> 2 -> 2 -> null
        //           l2
        // 1 -> 8 -> null
        int vUme = 0; // vUme = 0
        auto *ancor = new ListNode{}; // ancor = 0
        auto *cur = ancor; // cur = 0

        while (l1 || l2) { // 2 || null
            int sum = getVal(l1) + getVal(l2) + vUme; // sum = 3
            vUme = sum / 10; // vUme = 0
            if (!cur->next) {
                cur->next = new ListNode{}; // cur->next = 0
                cur = cur->next; // cur => cur->next
            }
            cur->val = sum % 10; // cur = 3
            l1 = l1 ? l1->next : nullptr; // l1 => l1->next
            l2 = l2 ? l2->next : nullptr; // l2 => l2->next
        }
        if (vUme) {
            cur->next = new ListNode{};
            cur = cur->next;
            cur->val = vUme;
        }
        return ancor->next;
    }

private:
    int getVal(ListNode *node) {
        if (node) return node->val;
        return 0;
    }
};