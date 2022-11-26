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
    ListNode *getIntersection(ListNode *const head) {
        auto *fast = head; // walks two steps
        auto *slow = head; // walks one step
        while ((fast != nullptr) && (fast->next != nullptr)) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        auto *intersection = getIntersection(head);
        if (intersection == nullptr) {
            return nullptr;
        }
        
        while (head != intersection) {
            head = head->next;
            intersection = intersection->next;
        }
        
        return head;
    }
};

/*  
a - b - c - d
     \_____/
   	      start |
ab bc cd 	~ a | b c d
ac cb bd 	~ a | bc db cd

head  : a -> b
inter : d -> b

---------------------------------

a - b - c - d - e
         \_____/
   	      start |
ab bc cd 	~ a | b c d
ac ce ed 	~ a | bc de cd

head  : a -> b -> c
inter : d -> e -> c
*/