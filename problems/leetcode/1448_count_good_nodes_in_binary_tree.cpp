#include <iostream>

struct TreeNode {
    int32_t val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int32_t x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int32_t x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int32_t goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + Helper(root->left, root->val) + Helper(root->right, root->val);
    }

    int32_t Helper(TreeNode* root, int32_t max_value) {
        if (root == nullptr) {
            return 0;
        }

        if (max_value <= root->val) {
            return 1 + Helper(root->left, root->val) + Helper(root->right, root->val);
        }

        return Helper(root->left, max_value) + Helper(root->right, max_value);
    }
};

/*
WOW solution
it's so good only because of
         mover->left = mover->right = nullptr;
improved cache locality: 
Smaller active memory footprint improves data locality, leading to better performance in some scenarios.
*/
// class Solution {
//     int ans=0;
// public:
//     void dfs(TreeNode* mover, int maxi){
//         if(mover==nullptr) return;
//         if(mover->val>=maxi){
//             ans++;
//             maxi=mover->val;
//         }
//         if(!(mover->left || mover->right)){
//             return;
//         }
//         dfs(mover->left, maxi);
//         dfs(mover->right, maxi);
//         mover->left = mover->right = nullptr;
//     }
//     int goodNodes(TreeNode* root) {
//         int maxi=root->val;
//         dfs(root, maxi);
//         root->left==root->right==NULL;
//         return ans;
//     }
// }