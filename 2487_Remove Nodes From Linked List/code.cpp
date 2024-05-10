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
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        auto *cur = head->next;
        auto *prev = head;
        while (cur) {
            if (cur->val >= prev->val) {
                prev->next = cur;
                prev = cur;
            }
            cur = cur->next;
        }
        prev->next = nullptr;
        return reverse(head);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        auto *cur = head;
        auto *next = head->next;
        while (cur) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next ? next->next : next;
        }
        return prev;
    }
};

// если реверснуть список результирующий, то видно что это неубыв посл и тогда 
// дальше через два указателя: один бежит в поисках узла со значением большим черем значение второго
// второй стоит и ждёт пока не найдется больший узел - если нашелся то переставляется на него

// 5 -> 2 -> 13 -> 3 -> 8

// 1. reverse
// p    c    n
// null 5 -> 2 -> 13 -> 3 -> 8

// p       c  n
// null <- 5  2 -> 13 -> 3 -> 8

//         p  c    n
// null <- 5  2 -> 13 -> 3 -> 8

// ...

//                    p    c  n
// null <- 5 <- 2 <- 13 <- 3  8 -> null

//                         p  c    n
// null <- 5 <- 2 <- 13 <- 3  8 -> null

//                              p  c n
// null <- 5 <- 2 <- 13 <- 3 <- 8 null

// 2. remove nodes:
//                         c    p
// null <- 5 <- 2 <- 13 <- 3 <- 8

//                    c         p
// null <- 5 <- 2 <- 13 <- 3 <- 8

//                    c    p
// null <- 5 <- 2 <- 13 <- 8

//              c    p
// null <- 5 <- 2 <- 13 <- 8

//         c         p
// null <- 5 <- 2 <- 13 <- 8

//  c                p
// null <- 5 <- 2 <- 13 <- 8

//  c      p
// null <- 13 <- 8