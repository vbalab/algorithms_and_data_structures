struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {  // NOLINT
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            if (root->left != nullptr) {
                root->right = insertNode(root->right, root->left);
            }

            return root->right;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        return root;
    }

    TreeNode* insertNode(TreeNode* root, TreeNode* node) {  // NOLINT
        if (root == nullptr) {
            return node;
        }

        if (node->val < root->val) {
            root->left = insertNode(root->left, node);
        } else {
            root->right = insertNode(root->right, node);
        }

        return root;
    }
};
