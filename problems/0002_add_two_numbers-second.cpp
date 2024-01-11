#include <iostream>
#include <vector>
#include "../utils.h"


using namespace utils;


struct ListNode
{
    int val;
    ListNode *next;
};


void printll(const ListNode* head) 
{
    while(head != nullptr) 
    {
        std::cout << "Value: " << head ->val << ", Next: " << head ->next << "\n";
        head = head ->next;
    }
};


void insert_after(ListNode*& node, const int val)
{
    ListNode* tempPtr = new ListNode;
    tempPtr ->val = val;

    node ->next = tempPtr;
    node = node ->next;
};


ListNode* reversed_linked_list_from_vector(const std::vector<int>& v)
{
    ListNode* headnode = new ListNode;
    headnode ->next = nullptr;

    ListNode* tmp = headnode;
    for(const auto& val : v)
    {
        insert_after(tmp, val);
    };

    return headnode ->next;
}


std::vector<int> vector_from_reversed_linked_list(const ListNode* head)
{
    std::vector<int> v;

    while (true)
    {
        v.push_back(head ->val);

        if (head ->next == nullptr)
            break;

        head = head ->next;
    };

    return v;
}


class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* headnode = new ListNode;
            headnode ->next = nullptr;

            bool cond1 = l1 ->next;
            bool cond2 = l2 ->next;
            int val1;
            int val2;
            int add_one = 0;
            int sum;


            ListNode* tmp = headnode;
            while (true)
            {
                cond1 = l1 != nullptr;
                cond2 = l2 != nullptr;

                if (cond1) {
                    val1 = l1 ->val;
                    l1 = l1 ->next;
                } else {
                    val1 = 0;
                };

                if (cond2) {
                    val2 = l2 ->val;
                    l2 = l2 ->next;
                } else {
                    val2 = 0;
                };


                if (!cond1 and !cond2 and add_one == 0)
                    break;
                
                sum = val1 + val2 + add_one;
                insert_after(tmp, sum % 10);

                add_one = sum / 10;
            };

            return headnode ->next;
        };
};


int main() 
{
    std::string input_line;
    std::vector<int> v;

    std::getline(std::cin, input_line);
    v = fill_vector_from_string(input_line);
    ListNode* headnode1 = reversed_linked_list_from_vector(v);
    printll(headnode1);
 

    std::getline(std::cin, input_line);
    v = fill_vector_from_string(input_line);
    ListNode* headnode2 = reversed_linked_list_from_vector(v);
    printll(headnode2);


    Solution solution;
    std::cout << "\nSolution: \n";
    printll(solution.addTwoNumbers(headnode1, headnode2));

    return 0;
};