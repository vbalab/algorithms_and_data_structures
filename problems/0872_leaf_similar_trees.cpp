#include <queue>
#include <sstream>
#include <iostream>


class TreeNode {
public:
    int val;

    TreeNode* left;
    TreeNode* right;


    TreeNode() { };


    TreeNode(int val) {
        this->val = val;

        this->left = nullptr;
        this->right = nullptr;
    };
};


template <typename T>
void fill_by_bfs(TreeNode*& root, std::queue<T>& values) {
    int values_size = values.size() - 1;        // -1 for the initial pop()

    std::vector<TreeNode*> nodes = { root };
    std::vector<TreeNode*> new_nodes;


    while (nodes.size() > 0) {
        new_nodes = { };

        for (TreeNode* node: nodes) {
            node->val = values.front();
            values.pop();


            if (values_size > 0) {
                node->left = new TreeNode();
                new_nodes.push_back(node->left);
                values_size--;
            };

            if (values_size > 0) {
                node->right = new TreeNode();
                new_nodes.push_back(node->right);
                values_size--;
            };
        };

        nodes = new_nodes;
    };
};


int height(TreeNode* node) {
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


void print_tree(std::vector<TreeNode*> level_nodes, int height, int lenght_of_num) {
    if (height == 0)
        return;


    int spaces_between = n_sum(height) + lenght_of_num;
    std::vector<TreeNode*> next_level_nodes;


    for (int i = 0; i < level_nodes.size() & level_nodes.size() > 1; i++) {
        std::cout.width(spaces_between);

        if (i % 2)
            std::cout << '\\';
        else
            std::cout << "/";
    };
    std::cout << '\n';


    for (const TreeNode* node: level_nodes) {
        std::cout.width(spaces_between);

        if (node == nullptr) {
            std::cout << '-';

            next_level_nodes.push_back(nullptr);
            next_level_nodes.push_back(nullptr);
        }
        else {
            std::cout << node->val;

            next_level_nodes.push_back(node->left);
            next_level_nodes.push_back(node->right);
        };
    };
    std::cout << '\n';


    print_tree(next_level_nodes, --height, lenght_of_num);
};


class Solution {
public:
    void getLeafs(TreeNode* root, std::vector<int>& leafs) {
        if (root->left == nullptr & root->right == nullptr)
            leafs.push_back(root->val);

        if (root->left != nullptr)
            getLeafs(root->left, leafs);
        if (root->right != nullptr)
            getLeafs(root->right, leafs);
    };


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> leafs1;
        std::vector<int> leafs2;

        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);

        return leafs1 == leafs2;
    };
};


int main() {
    std::string input_line;
    std::istringstream stream;
    int input;


    std::queue<int> q1;
    std::queue<int> q2;


    std::getline(std::cin, input_line);
    stream.str(input_line);

    while (stream >> input)
            q1.push(input);

    stream.clear();


    std::getline(std::cin, input_line);
    stream.str(input_line);

    while (stream >> input)
            q2.push(input);


    TreeNode* root1 = new TreeNode();
    fill_by_bfs(root1, q1);

    TreeNode* root2 = new TreeNode();
    fill_by_bfs(root2, q2);


    std::cout << "Modified level traversal:";
    print_tree({ root1 }, height(root1), 2);

    std::cout << "Modified level traversal:";
    print_tree({ root2 }, height(root2), 2);


    Solution s;  
    std::cout << static_cast<int>(s.leafSimilar(root1, root2)) << '\n';

    return 0;
};
