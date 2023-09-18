// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.



// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

// lists.size: [0..50]
// node.val: [-100..100]
// lists are sorted in non-decreasing order

//                   l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix, free (free will go over the new list)
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                   r
// 1 < 1?

//                   l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                        r
//  fix -> 1
// 1 < 3?

//                        l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                        r
//  fix -> 1 -> 1
// 2 < 3?

//                             l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                        r
//  fix -> 1 -> 1 -> 2
// 4 < 3?

//                             l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                             r
//  fix -> 1 -> 1 -> 2 -> 3
// 4 < 4?

//                             l
//      _________/-> 1 -> 2 -> 4
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                                  r
//  fix -> 1 -> 1 -> 2 -> 3 -> 4
// 4 < 5?

//                                   l
//      _________/-> 1 -> 2 -> 4 -> null
//     /
//   fix
//     \_________
//               \-> 1 -> 3 -> 4 -> 5 -> 6
//                                  r
//  fix -> 1 -> 1 -> 2 -> 3 -> 4 -> 4
// null < 5? -> stop
// append 5->6 to result
// return fix

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
class Solution {
public:
    // time: O(N); mem: O(1)
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        //                l
        // 1 -> 2 -> 4 -> null
        // 1 -> 3 -> 4 -> 5 -> null
        //                r
        // fix -> 1(r) -> 1(l) -> 2(l) -> 3(r) -> 4(r) -> 4(l) -> 5(l)
        //                                                free
        ListNode *fix = new ListNode{0}; // fix = 0
        auto *free = fix; // free = 0
        while (first != nullptr && second != nullptr) { // null != nullptr && 5 != nullptr
            if (first->val < second->val) { // 4 < 5
                free->next = first; // free->next = 4(l)
                first = first->next; // first = null
            } else {
                free->next = second; // free->next = 4(r)
                second = second->next; // second = 5
            }
            free = free->next; // free = 4(l)
        }
        if (first) { // null
            free->next = first;
        }
        if (second) { // 5
            free->next = second;
        }
        return fix->next;
    }


    // naive. O(N) memory, but can O(1) if can modify input lists
    ListNode* mergeTwoListsNaive(ListNode* first, ListNode* second) {
        ListNode *head = nullptr;
        if (!first && !second) {
            return head;
        }
        if (!first) {
            return second;
        }
        if (!second) {
            return first;
        }
        if (first->val < second->val) {
            head = new ListNode(first->val);
            first = first->next;
        } else {
            head = new ListNode(second->val);
            second = second->next;
        }

        auto *cur = head;
        while ((first != nullptr) && (second != nullptr)) {
            if (first->val < second->val) {
                cur->next = new ListNode(first->val);
                first = first->next;
            } else {
                cur->next = new ListNode(second->val);
                second = second->next;
            }
            cur = cur->next;
        }
        // догнать первый если осталось
        while (first != nullptr) {
            cur->next = new ListNode(first->val);
            cur = cur->next;
            first = first->next;
        }
        // догнать второй если осталось
        while (second != nullptr) {
            cur->next = new ListNode(second->val);
            cur = cur->next;
            second = second->next;
        }
        return head;
    }
};