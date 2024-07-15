#include <vector>
#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class SolutionBad {
public:
    bool isSymmetric(TreeNode* root) {
        std::vector<TreeNode*> left = {root->left};
        std::vector<TreeNode*> right = {root->right};
        std::vector<TreeNode*> left_new;
        std::vector<TreeNode*> right_new;
        int s;

        while (left.size() || right.size()) {    
            if (left.size() != right.size())
                return false;

            s = left.size();
            left_new.clear();
            right_new.clear();

            for (int i = 0; i < s; i++) {
                if (!left[s - i - 1] ^ !right[i])
                    return false;
                if ((left[s - i - 1] && right[i]) && left[s - i - 1]->val != right[i]->val)
                    return false;
            }

            for (int i = 0; i < s; i++) {
                if (left[i]) {
                    left_new.push_back(left[i]->left);
                    left_new.push_back(left[i]->right);
                }

                if (right[i]) {
                    right_new.push_back(right[i]->left);
                    right_new.push_back(right[i]->right);
                }
            }

            left = left_new;
            right = right_new;
        }

        return true;
    }
};


class Solution {
public:
    bool aux(TreeNode* left, TreeNode* right) {
        if (!left || !right)
            return left == right;

        return (left->val == right->val) && aux(left->left, right->right) && aux(left->right, right->left);
    }


    bool isSymmetric(TreeNode* root) {
        return aux(root->left, root->right);
    }
};


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution s;
    s.isSymmetric(root);

    return 0;
}
