// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

// list.size: [0..5000]
// node.val: [-5000..5000]

//        tmp
//        cur
// prev
// null -> 1 -> 2 -> 3 -> 4 -> 5 -> null

//        tmp
//             cur
// prev
// null -> 1 -> 2 -> 3 -> 4 -> 5 -> null

//        tmp
//             cur
// prev
// null <- 1    2 -> 3 -> 4 -> 5 -> null

//        tmp
//             cur
//        prev
// null <- 1    2 -> 3 -> 4 -> 5 -> null

//             tmp
//             cur
//        prev
// null <- 1    2 -> 3 -> 4 -> 5 -> null

// repeate

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
class Solution { // time: O(n); mem: O(1)
public:
    ListNode* reverseList(ListNode* head) {
        // 1 -> 2 -> 3 -> 4 -> 5
        ListNode *prev = nullptr; // prev = 5
        auto *cur = head; // cur = nullptr
        while (cur != nullptr) { // nullptr != nullptr
            auto *tmp = cur; // tmp = 5
            cur = cur->next; // cur = nullptr
            tmp->next = prev; // tmp->next = 4
            prev = tmp; // prev = 5
        }
        return prev;
    }
};