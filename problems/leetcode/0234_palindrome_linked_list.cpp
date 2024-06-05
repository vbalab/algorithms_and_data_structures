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
    ListNode* head;

    bool isPalindrome(ListNode* head) {
        this->head = head;

        // get to the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        };


        return solve(slow);
    };


    bool solve(ListNode* tail) {
        if (tail == nullptr)
            return true;

        bool is = solve(tail->next) && tail->val == head->val;
        
        head = head->next;

        return is;
    };
};


int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    std::cout << s.isPalindrome(head) << '\n';

    return 0;
};
