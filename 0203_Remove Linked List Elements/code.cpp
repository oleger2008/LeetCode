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

// [1, 2, 6, 3, 4, 5, 6] null
//                 pr    c

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while ((head != nullptr) && (head->val == val)) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }

        auto *prev = head;
        auto *cur = head->next;
        while (cur != nullptr) {
            if (cur->val == val) {
                prev->next = cur->next;
            } else {
                prev = cur;
            }
            cur = cur->next;
        }
        
        
        return head;
    }
};