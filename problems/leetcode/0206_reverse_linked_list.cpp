#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution_recursive {
public:
    ListNode* tail;

    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;

        this->reverseList_(head);
        head->next = nullptr;

        return tail;
    }


    ListNode* reverseList_(ListNode* head) {
        if (!head->next) {
            this->tail = head;

            return head;
        }

        ListNode* next = reverseList_(head->next);
        next->next = head;


        return head;
    }
};


class Solution_loop {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;


        ListNode* prev = head;
        ListNode* next = head->next;
        head->next = nullptr;

        while (next) {
            head = next;
            next = head->next;

            head->next = prev;

            prev = head;
        }

        return head;
    }
};



int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);


    Solution_loop s;
    head = s.reverseList(head);

    while (head) {
        std::cout << head->val << ' ';
        head = head->next;
    }
    std::cout << '\n';

    return 0;
}
