// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

// arr.size: [0..10^4]
// list.size: [0..500]
// node.val: [-10^4..10^4]
// sum of lists[i].length <= 10^4

// fake_head
// [
//   l1
//   1 -> 4 -> 5,
//   l2
//   1 -> 3 -> 4,
//   l3
//   2 -> 6
// ]
// cur = l1 and then check every

// fake_head -> 1
// [
//        l1
//   1 -> 4 -> 5,
//   l2
//   1 -> 3 -> 4,
//   l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1
// [
//        l1
//   1 -> 4 -> 5,
//        l2
//   1 -> 3 -> 4,
//   l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2
// [
//        l1
//   1 -> 4 -> 5,
//        l2
//   1 -> 3 -> 4,
//        l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2 -> 3
// [
//        l1
//   1 -> 4 -> 5,
//             l2
//   1 -> 3 -> 4,
//        l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2 -> 3 -> 4
// [
//             l1
//   1 -> 4 -> 5,
//             l2
//   1 -> 3 -> 4,
//        l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2 -> 3 -> 4 -> 4
// [
//             l1
//   1 -> 4 -> 5,
//                  l2
//   1 -> 3 -> 4 -> null,
//        l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
// [
//                  l1
//   1 -> 4 -> 5 -> null,
//                  l2
//   1 -> 3 -> 4 -> null,
//        l3
//   2 -> 6
// ]

// fake_head -> 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5
// [
//                  l1
//   1 -> 4 -> 5 -> null,
//                  l2
//   1 -> 3 -> 4 -> null,
//             l3
//   2 -> 6 -> null
// ]

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
class Solution { // time: O(lists.count * nodes.count); mem: O(1)
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //                                                                               iter
        // before_head -> 1(l0) -> 1(l1) -> 2(l2) -> 3(l1) -> 4(l0) -> 4(l1) -> 5(l0) -> 6(l2)
        //     [
        //                       l0
        //     0  1 -> 4 -> 5 -> null,
        //                       l1
        //     1  1 -> 3 -> 4 -> null,
        //                  l2
        //     2  2 -> 6 -> null
        //     ]
        ListNode before_head{-1};
        auto *iter = &before_head; // iter = -1
        while (true) {
            int cur = -1; // cur = -1
            for (int i = 0; i < lists.size(); ++i) { // i = 2
                if (lists[i]) { // l2=null
                    cur = i; // cur =
                    break;
                }
            }
            if (cur == -1) break; // -1 == -1 - true
            for (int i = cur; i < lists.size(); ++i) { // i = 2
                if (lists[i] && (lists[i]->val < lists[cur]->val)) { // l[2]=6 && 6 < 6
                    cur = i; // cur =
                }
            }
            iter->next = lists[cur];
            iter = iter->next;
            lists[cur] = lists[cur]->next;
        }
        return before_head.next;
    }
};