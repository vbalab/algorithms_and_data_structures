#include <iostream>
#include <vector>


// Tree - hierarchical d.s.

// DFS (Depth First Traversals): inorder, preorder, postorder
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;

        // this->left = nullptr;           // if not provided, then left filled with garbage address in case of: Node smth = Node(10);
        // this->right = nullptr;
    };
};


void inorder_traversal(Node* node) {
    if (node != nullptr) {
        inorder_traversal(node->left);

        std::cout << node->data << ' ';

        inorder_traversal(node->right);
    };
};


void preorder_traversal(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << ' ';

        preorder_traversal(node->left);
        preorder_traversal(node->right);
    };
};


void postorder_traversal(Node* node) {
    if (node != nullptr) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);

        std::cout << node->data << ' ';
    };
};


int height(Node* node) {
    if (node == nullptr)
        return 0;

    return 1 + std::max(height(node->left), height(node->right));
};


int n_sum(int n) {
    int sum = 0;

    while (n != 0)
        sum += n--;

    return sum;
};


void print_tree(std::vector<Node*> level_nodes, int height, int lenght_of_num) {
    if (height == 0)
        return;


    int spaces_between = n_sum(height) + lenght_of_num;
    std::vector<Node*> next_level_nodes;


    for (int i = 0; i < level_nodes.size() & level_nodes.size() > 1; i++) {
        std::cout.width(spaces_between);

        if (i % 2)
            std::cout << '\\';
        else
            std::cout << "/";
    };
    std::cout << '\n';


    for (const Node* node: level_nodes) {
        std::cout.width(spaces_between);

        if (node == nullptr) {
            std::cout << '-';

            next_level_nodes.push_back(nullptr);
            next_level_nodes.push_back(nullptr);
        }
        else {
            std::cout << node->data;

            next_level_nodes.push_back(node->left);
            next_level_nodes.push_back(node->right);
        };
    };
    std::cout << '\n';


    print_tree(next_level_nodes, --height, lenght_of_num);
};


int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(40);
    root->left->left->right = new Node(0);
    root->right = new Node(-10);
    root->right->left = new Node(30);


    std::cout << "Inorder traversal: ";
    inorder_traversal(root);
    std::cout << '\n';

    std::cout << "Preorder traversal: ";
    preorder_traversal(root);
    std::cout << '\n';

    std::cout << "Postorder traversal: ";
    postorder_traversal(root);
    std::cout << '\n';


    std::cout << "Height: " << height(root) << '\n';

    std::cout << "Level traversal:";
    print_tree({root}, height(root), 2);




    Node* smth1 = new Node(10);
    Node smth2 = Node(10);

    std::cout << smth1->left << '\n';
    std::cout << smth2.left << '\n';
    return 0;
};