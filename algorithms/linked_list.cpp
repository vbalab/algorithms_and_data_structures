#include <iostream>
#include <string>

// linked list - chain of elements with a pointer to the following element

// head node -> node -> node -> ... -> node -> null pointer (to indicate the end)
// each node has data and pointer to another node

// linked list excels in incertion and deletion of nodes in O(1) in runtime; but getting to particular node - O(n)
// vector excels in getting an element in O(1) in runtime (because of hashmapping - indexes)

// l.l. makes stack, queue


// via struct or class

struct Node
{
    int data;
    Node* link;
};


void insert_before(Node*& node, int data) 
{
    Node* tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->link = node;

    node = tempPtr;
};


void insert_after(Node*& node, int data) 
{
    Node* tempPtr = new Node;
    tempPtr->data = data;
    tempPtr->link = node->link;

    node->link = tempPtr;
};


int main()
{
    Node* headNode = new Node;
    headNode->data = 20;
    headNode->link = nullptr;

    insert_before(headNode, 30);
    insert_after(headNode->link, 40);

    Node* tmp = headNode;
    while(tmp != nullptr) {
        std::cout << tmp->data << ";" << tmp << ";" << tmp->link << "\n";
        tmp = tmp->link;
    };

    return 0;
};
