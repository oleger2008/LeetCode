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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        } else if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        
        ListNode* temp = nullptr;
        if (l1->val < l2->val) {
            temp = l1;
            goNext(l1);
        } else {
            temp = l2;
            goNext(l2);
        }
        ListNode* result = temp;
        
        while ((l1 != nullptr) && (l2 != nullptr)) {
            if (l1->val < l2->val) {
                temp->next = l1;
                goNext(l1);
            } else {
                temp->next = l2;
                goNext(l2);
            }
            goNext(temp);
        }
        
        temp->next = (l1 != nullptr) ? l1 : l2;
        return result;
    }
    
private:
    void goNext(ListNode* &node) {
        if (node == nullptr) {
            return;
        }
        node = node->next;
    }
};

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode result;
//         ListNode *head = &result;

//         while (l1 != nullptr && l2 != nullptr) {
//             if (l1->val < l2->val) {
//                 head->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 head->next = l2;
//                 l2 = l2->next;
//             }

//             head = head->next;
//         }

//         if (l1) {
//             head->next = l1;
//         }
//         else if (l2) {
//             head->next = l2;
//         }
//         return result.next;
//     }
// };