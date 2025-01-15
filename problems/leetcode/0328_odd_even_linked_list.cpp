#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd_head = head;
        ListNode* odd_tail = head;
        ListNode* even_head = head->next;
        ListNode* even_tail = head->next;

        while (even_tail && even_tail->next) {
            odd_tail->next = even_tail->next;
            odd_tail = odd_tail->next;

            even_tail->next = odd_tail->next;
            even_tail = even_tail->next;

            odd_tail->next = even_head;
        }

        return odd_head;
    }
};