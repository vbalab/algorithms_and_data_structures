#include <iostream>
#include <vector>


struct ListNode
{
    int val;
    ListNode *next;
};


void printll(const ListNode* tmp) 
{
    while(tmp != nullptr) 
    {
        std::cout << "Value: " << tmp ->val << ", Next: " << tmp ->next << "\n";
        tmp = tmp ->next;
    }
};


void insert_after(ListNode*& node, int val)
{
    ListNode* tempPtr = new ListNode;
    tempPtr ->val = val;
    tempPtr ->next = node ->next;

    node ->next = tempPtr;
    node = tempPtr;
};


ListNode* reversed_linked_list_from_number(const std::vector<int>& number)
{
    ListNode* headnode = new ListNode;
    headnode ->next = nullptr;
    headnode ->val = number % 10;
    number = number / 10;

    ListNode* tmp = headnode;
    while(number > 0)
    {
        insert_after(tmp, number % 10);
        number = number / 10;
    };

    return headnode;
}


class Solution_first
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            unsigned long long number = get_total_reversed_number(l1) + get_total_reversed_number(l2);
            ListNode* headnode = reversed_linked_list_from_number(number);

            return headnode;
        };


        std::vector<int> get_total_reversed_number(ListNode* l)
        {
            unsigned long long number = 0;
            unsigned long long mult = 1;

            while(l != nullptr) 
            {
                number += mult * l ->val;

                mult *= 10;
                l = l ->next;
            };

            return number;
        };
};


class Solution_second
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            

            return headnode;
        };
};


int main() 
{
    std::vector<int> number;
    std::cin >> number;
    ListNode* headnode1 = reversed_linked_list_from_number(number);
    printll(headnode1);
 
    std::cin >> number;
    ListNode* headnode2 = reversed_linked_list_from_number(number);
    printll(headnode2);

    // ListNode* headnode1 = new ListNode;
    // headnode1 ->val = 2;
    // headnode1 ->next = nullptr;

    // insert_after(headnode1, 4);
    // insert_after(headnode1 ->next, 3);


    // ListNode* headnode2 = new ListNode;
    // headnode2 ->val = 5;
    // headnode2 ->next = nullptr;

    // insert_after(headnode2, 6);
    // insert_after(headnode2 ->next, 4);


    // Solution_first solution;
    Solution_second solution;
    std::cout << "\nSolution: \n";
    printll(solution.addTwoNumbers(headnode1, headnode2));

    return 0;
};