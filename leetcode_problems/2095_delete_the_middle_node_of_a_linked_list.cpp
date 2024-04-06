#include <vector>
#include <iostream>
#include "../utils.h"


struct Node {
    int val;
    Node* next;


    Node() {
        val = 0;
        next = nullptr;
    };

    Node(int data, Node* next) {
        val = data;
        next = next;
    };
};


void insert_after(Node*& node, int data) 
{
    Node* tempPtr = new Node(data, node->next);

    node->next = tempPtr;
};


class Solution {
public:
    Node* deleteMiddle(Node* headNode) {
        if (headNode->next == nullptr)
            return nullptr;


        Node* lastNode = headNode;
        int size = 1;

        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
            size++;
        };


        Node* PreviousToMiddleNode = headNode;
        int i = 0;

        while (i < (size / 2) - 1) {
            PreviousToMiddleNode = PreviousToMiddleNode->next;
            i++;
        }


        Node* del = PreviousToMiddleNode->next;

        PreviousToMiddleNode->next = PreviousToMiddleNode->next->next;

        delete del;

        return headNode;
    };
};


// Really good, but not mine:
class Solution_other {
public:
    Node* deleteMiddle(Node* head) {
        if(head->next == nullptr)
            return nullptr;


        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;


        while(fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }
};


int main() {
    std::string input_line;
    std::getline(std::cin, input_line);

    std::vector<int> nums = utils::fill_vector_from_string(input_line);


    Node* headNode = new Node(nums[0], nullptr);


    Node* tmpNode = headNode;
    for (int i = 1; i < nums.size(); i++) {
        insert_after(tmpNode, nums[i]);
        tmpNode = tmpNode->next;
    };


    Solution solution;
    headNode = solution.deleteMiddle(headNode);


    tmpNode = headNode;
    while (tmpNode != nullptr) {
        std::cout << tmpNode->val << ' ';
        tmpNode = tmpNode->next;
    }
    std::cout << '\n';


    return 0;
};
