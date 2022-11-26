/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *const head) {
        auto *rabbit = head; // walks two steps
        auto *turtle = head; // walks one step
        while ((rabbit != nullptr) && (rabbit->next != nullptr)) {
            rabbit = rabbit->next->next;
            turtle = turtle->next;
            if (rabbit == turtle) {
                return true;
            }
        }
        return false;
    }
};