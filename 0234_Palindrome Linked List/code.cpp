// Given the head of a singly linked list, return true if it is a
// palindrome or false otherwise.

// Example 1:
// 1 -> 2 -> 2 -> 1
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// 1 -> 2
// Input: head = [1,2]
// Output: false

// list.size: [1..10^5]
// node.val: [0..9]

// 1. find middle of linked list
// 2. reverse right half of linked list
// 3. start compare two halfs

//-------------------------------------

// 1. find middle of linked list
// s
// f
// 1 -> 2 -> 2 -> 1 -> null

//      s
//           f
// 1 -> 2 -> 2 -> 1 -> null

//           s
//                     f
// 1 -> 2 -> 2 -> 1 -> null

// 2. reverse second half
//           cur
//           tmp
// 1 -> 2 -> 2 -> 1 -> null
//
//     null
//     prev

//                cur
//           tmp
// 1 -> 2 -> 2 -> 1 -> null
//
//     null
//     prev

//                      cur
//                tmp
// 1 -> 2 ->  - <- 2    1 -> null
//          /
//     null
//     prev

//                      cur
//                tmp
// 1 -> 2 ->  - <- 2    1 -> null
//          /
//     null
//                prev

//                      cur
//                      tmp
// 1 -> 2 ->  - <- 2    1 -> null
//          /
//     null
//                prev

//                           cur
//                      tmp
// 1 -> 2 ->  - <- 2    1 -> null
//          /
//     null
//                prev

//                           cur
//                      tmp
// 1 -> 2 ->  - <- 2 <- 1    null
//          /
//     null
//                prev

//                           cur
//                      tmp
// 1 -> 2 ->  - <- 2 <- 1    null
//          /
//     null
//                      prev

// 3. start compare two halfs
// head
// 1 -> 2 ->  - <- 2 <- 1    null
//          /
//     null
//                      prev

//      head
// 1 -> 2 ->  - <- 2 <- 1    null
//          /
//     null
//                 prev

//                 head
// 1 -> 2 ->  - <- 2 <- 1    null
//          /
//     null (cond for stop)
//     prev

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

class Solution { // time: O(n), mem: O(1)
public:
    bool isPalindrome(ListNode *const head) {
        // 1. find middle of linked list
        auto *slow = head;
        auto *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. reverse second half
        ListNode *prev = nullptr;
        auto *cur = slow;
        while (cur) {
            auto *tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }

        // 3. start compare two halfs
        auto *left = head;
        auto *right = prev;
        while (right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};