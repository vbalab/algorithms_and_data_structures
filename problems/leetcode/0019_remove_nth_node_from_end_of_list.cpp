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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before_nth = head;
        ListNode* end = head;
        int i = 0;


        while (end->next != nullptr) {
            if (i >= n)
                before_nth = before_nth->next;
            end = end->next;
            i++;
        };


        if (head == end)
            return nullptr;
        else if (head == before_nth && n != i)
            return head->next;
        else {
            before_nth->next = before_nth->next->next;

            return head;
        }
    };
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);

    Solution s;
    s.removeNthFromEnd(head, 1);

    return 0;
};
