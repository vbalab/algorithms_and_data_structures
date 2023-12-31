#include <iostream>


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


// void insert_before(ListNode*& node, int val)
// {
//     ListNode* tempPtr = new ListNode;
//     tempPtr ->val = val;
//     tempPtr ->next = node;

//     node = tempPtr;
// }


// ListNode* linked_list_from_number(int number)
// {
//     ListNode* headnode = new ListNode;
//     headnode ->next = nullptr;
//     headnode ->val = number % 10;
//     number = number / 10;

//     ListNode* tmp = headnode;
//     while(number > 0)
//     {
//         insert_before(tmp, number % 10);
//         number = number / 10;

//     };

//     return tmp;
// };


// int reverse_digits(int number)
// {
//     int rev_number = 0;

//     while (number > 0)
//     {
//         rev_number = rev_number * 10 + number % 10;
//         number = number / 10;
//     }

//     return rev_number;
// };


void insert_after(ListNode*& node, int val)
{
    ListNode* tempPtr = new ListNode;
    tempPtr ->val = val;
    tempPtr ->next = node ->next;

    node ->next = tempPtr;
    node = tempPtr;
};


ListNode* reversed_linked_list_from_number(unsigned long long number)
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


class Solution 
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            unsigned long long number = get_total_reversed_number(l1) + get_total_reversed_number(l2);
            ListNode* headnode = reversed_linked_list_from_number(number);

            return headnode;
        };


        unsigned long long get_total_reversed_number(ListNode* l)
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


int main() 
{
    unsigned long long number;
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


    Solution solution;
    std::cout << "\nSolution: \n";
    printll(solution.addTwoNumbers(headnode1, headnode2));

    return 0;
};