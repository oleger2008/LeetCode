// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

// list.size: [1..30]
// node.val: [0..100]
// n: [1..list.size]


// idea: use symmetry: n - distance from right corner
// if we have slow and fast ptr, where fast starts in distance n
// symetric to anouther edge, so after going till fast != end node
// slow would be befor node_to_delete

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
    ListNode* removeNthFromEnd(ListNode* head, int n) { // n = 1
        //  s
        //       f
        // -1 -> 1 -> null
        ListNode before_head{-1, head};
        auto *fast = &before_head; // fast = -1
        for (int i = 0; i < n; ++i) { // i = 1
            fast = fast->next; // fast = 1
        }
        auto *slow = &before_head; // slow = -1
        while (fast->next) { // fast->next = null
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return before_head.next;
    }
};