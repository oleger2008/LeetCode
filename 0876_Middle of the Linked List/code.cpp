// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

// list.size: [1..100]
// node.val: [1..100]

// s
// f
// 1 -> 2 -> 3 -> 4 -> 5 -> null

//      s
//           f
// 1 -> 2 -> 3 -> 4 -> 5 -> null

//           s
//                     f
// 1 -> 2 -> 3 -> 4 -> 5 -> null
// ans: s = 3

// ------------

// s
// f
// 1 -> 2 -> 3 -> 4 -> 5 -> 6-> null

//      s
//           f
// 1 -> 2 -> 3 -> 4 -> 5 -> 6-> null

//           s
//                     f
// 1 -> 2 -> 3 -> 4 -> 5 -> 6-> null

//                s
//                              f
// 1 -> 2 -> 3 -> 4 -> 5 -> 6-> null
// ans: s = 4

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
class Solution { // time: O(N), mem: O(1)
public:
    ListNode* middleNode(ListNode* head) {
        //                s
        //                                f
        // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
        auto *slow = head; // slow = 1
        auto *fast = head; // fast = 1
        while (fast && fast->next) { // null != null && _ != null
            slow = slow->next; // slow = 4
            fast = fast->next->next; // fast = null
        }
        return slow;
    }
};