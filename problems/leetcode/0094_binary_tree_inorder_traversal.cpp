#include <cstdint>
#include <iostream>
#include <iterator>
#include <vector>

struct TreeNode {
    int32_t val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int32_t val) : val(val) {}
};

class Solution {
public:
    std::vector<int32_t> inorderTraversal(TreeNode* root) {
        std::vector<int32_t> result;
        return inorderTraversal(root, result);
    }

    std::vector<int32_t> inorderTraversal(TreeNode* root,
                                          std::vector<int32_t>& result) {
        if (root == nullptr) {
            return result;
        }

        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);

        return result;
    }
};

int main() {
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(0);
    node->right = new TreeNode(3);
    node->right->left = new TreeNode(2);

    Solution solution;
    std::vector<int32_t> vec = solution.inorderTraversal(node);

    std::copy(vec.begin(), vec.end(),
              std::ostream_iterator<int64_t>(std::cout, ", "));

    return 0;
}
