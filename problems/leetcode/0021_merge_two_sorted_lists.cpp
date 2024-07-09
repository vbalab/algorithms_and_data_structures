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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* tmp = head;


        while (list1 && list2) {
            if (list1->val < list2->val) {
                tmp->next = list1;
                list1 = list1->next;
            }
            else {
                tmp->next = list2;
                list2 = list2->next;
            }

            tmp = tmp->next;
        }

        while (list1) {
            tmp->next = list1;
            list1 = list1->next;

            tmp = tmp->next;
        }   

        while (list2) {
            tmp->next = list2;
            list2 = list2->next;

            tmp = tmp->next;
        }


        return head->next;
    }
};


int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(3);
    head1->next->next = new ListNode(5);
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(4);

    Solution s;
    s.mergeTwoLists(head1, head2);


    return 0;
}
