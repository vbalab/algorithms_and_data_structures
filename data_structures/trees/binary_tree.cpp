#include <queue>
#include <vector>
#include <iostream>
#include <stack>

/*
Tree - hierarchical d.s.

Types of traversals:
    DFS (Depth First search): inorder, preorder, postorde;
    BFS (breadth first search).

Height of a complete BT is [log_2{n - 1}] + 1
Height of a balanced BT is ~ [log_2{n - 1}] + 1
*/


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {};

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


void preorder_traversal_no_recursion(Node* node) {
    std::stack<Node*> stack;

    while (node) {
        while (node) {
            stack.push(node);

            std::cout << node->data << ' ';

            node = node->left;
        };


        node = stack.top();

        while (!node->right & !stack.empty()) {
            stack.pop();

            if (stack.empty())
                return;

            node = stack.top();
        };

        node = node->right;
        stack.pop(); 

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


void bfs(std::vector<Node*> level_nodes) {
    if (level_nodes.size() == 0)
        return;


    std::vector<Node*> next_level_nodes;

    for (const Node* node: level_nodes) {
        std::cout << node->data << ' ';

        if (node->left != nullptr)
            next_level_nodes.push_back(node->left);

        if (node->right != nullptr)
            next_level_nodes.push_back(node->right);
    };


    std::cout << '\n';
    bfs(next_level_nodes);
};


// modified BFS:
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



template <typename T>
void fill_by_bfs(Node*& root, std::queue<T>& values) {
    int values_size = values.size() - 1;        // -1 for the initial pop()

    std::vector<Node*> nodes = { root };
    std::vector<Node*> new_nodes;


    while (nodes.size() > 0) {
        new_nodes = { };

        for (Node* node: nodes) {
            node->data = values.front();
            values.pop();


            if (values_size > 0) {
                node->left = new Node();
                new_nodes.push_back(node->left);
                values_size--;
            };

            if (values_size > 0) {
                node->right = new Node();
                new_nodes.push_back(node->right);
                values_size--;
            };
        };

        nodes = new_nodes;
    };
};


int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(40);
    root->left->left->right = new Node(0);
    root->right = new Node(-10);
    root->right->left = new Node(30);


    std::cout << "(DFS) Inorder traversal: ";
    inorder_traversal(root);
    std::cout << '\n';

    std::cout << "(DFS) Preorder traversal: ";
    preorder_traversal(root);
    std::cout << '\n';

    std::cout << "(DFS) Postorder traversal: ";
    postorder_traversal(root);
    std::cout << '\n';

    std::cout << "(DFS) Preorder traversal - no recursion: ";
    preorder_traversal_no_recursion(root);
    std::cout << '\n';

    std::cout << "Height: " << height(root) << '\n';


    std::cout << "BFS = Level traversal:\n";
    bfs({root});

    std::cout << "Modified level traversal:";
    print_tree({root}, height(root), 2);


    return 0;
};