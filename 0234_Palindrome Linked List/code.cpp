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

// [1, 2, 3, 2, 1] NULL
// 1, 2, 3 <- mid
// 1, 3, 1
    
// [1, 2, 3, 1] NULL
// 1, 2, 3 <- mid
// 1, 3, NULL

// [1, 2] NULL
// 1, 2 <- mid
// 2, NULL

class Solution {
public:
    // v1 My naive
    bool isPalindrome(ListNode *const head) {
        if (head == nullptr) {
            return false;
        }
        auto *slow = head;
        auto *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //try to reverse right half of list
        auto *prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        while (slow != nullptr) {
            auto *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        slow = prev;
        fast = head;
        while (slow != nullptr) {
            if (slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};