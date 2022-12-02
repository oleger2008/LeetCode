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
    // mine
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) {
//             return nullptr;
//         }
//         ListNode *prev = nullptr;
//         auto *temp = head->next;
//         auto *cur = head;
//         while (temp != nullptr) {
//             cur->next = prev;
            
//             prev = cur;
//             cur = temp;
//             temp = temp->next;
//         }
//         cur->next = prev;
//         return cur;
//     }
    
    // other better
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = nullptr;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};