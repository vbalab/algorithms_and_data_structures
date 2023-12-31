#include <iostream>
#include <string>

// linked list - chain of elements with a pointer to the following element

// head node -> node -> node -> ... -> node -> null value (to indicate the end)
// each node has data and pointer to another node

// linked list excels in incertion and deletion of nodes in O(1) in runtime; but getting to particular node - O(n)
// vector excels in getting an element in O(1) in runtime (because of hashmapping - indexes)

// l.l. makes stack, queue


// via struct or class

struct Node
{
    int data;
    Node *link;
};


void insert_before(Node*& before_node, int data) 
{
    Node* tempPtr = new Node;
    tempPtr ->data = data;
    tempPtr ->link = before_node;

    before_node = tempPtr;
};


void insert_after(Node*& after_node, int data) 
{
    Node* tempPtr = new Node;
    tempPtr ->data = data;
    tempPtr ->link = after_node ->link;

    after_node ->link = tempPtr;
};


int main()
{
    Node* headNode = new Node;
    headNode ->data = 20;
    headNode ->link = NULL;

    insert_before(headNode, 30);
    insert_after(headNode ->link, 40);

    Node* tmp = headNode;
    while(tmp != NULL) {
        std::cout << tmp ->data << ";" << tmp << ";" << tmp ->link << "\n";
        tmp = tmp ->link;
    };

};
