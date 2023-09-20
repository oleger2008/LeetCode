// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// 3 -> 2 -> 0 -> -4
//      |          |
//       <---------
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// 1 -> 2
// |    |
//  <---
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// 1
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

// list.size: [0..10^4]
// cycle pos: -1 or valid list idx
// node.val: [-10^5..10^5]

// idea: use slow fast ptr

// s
// f
// 3 -> 2 -> 0 -> -4
//      |          |
//       <---------

//      s
//           f
// 3 -> 2 -> 0 -> -4
//      |          |
//       <---------

//           s
//
// 3 -> 2 -> 0 -> -4
//      |          |
//       <---------
//      f

//                 s
//                 f
// 3 -> 2 -> 0 -> -4
//      |          |
//       <---------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution { // time: O(n); mem: O(1)
public:
    bool hasCycle(ListNode *head) {
        auto *slow = head;
        auto *fast = head;
        do {
            if (!fast || !fast->next) return false;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);
        return true;
    }
};