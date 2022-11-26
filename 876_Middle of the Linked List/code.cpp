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
    // naive
    // ListNode* middleNode(ListNode* head) {
    //     size_t size = 0u;
    //     auto *node = head;
    //     while (node != nullptr) {
    //         node = node->next;
    //         ++size;
    //     }
    //     size = size / 2;
    //     for (size_t i = 0u; i < size; ++i) {
    //         head = head->next;
    //     }
    //     return head;
    // }
    
    // fast slow ptr
    ListNode *middleNode(ListNode *const head) {
        auto *slow = head;
        auto *fast = head;
        
        while ((fast != nullptr) && (fast->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};