#include <cstdint>
#include <vector>

class Solution {
    enum class TreeNodeState { White, Gray };

    struct TreeNode {
        std::vector<TreeNode*> children;
        std::vector<TreeNode*> parents;
        TreeNodeState state = TreeNodeState::White;
    };

public:
    int32_t minReorder(  // NOLINT
        int32_t n, const std::vector<std::vector<int32_t>>& connections) {
        std::vector<TreeNode*> nodes(n);

        for (int i = 0; i < n; ++i) {
            nodes[i] = new TreeNode();
        }

        for (const std::vector<int32_t>& connection : connections) {
            nodes[connection[0]]->children.push_back(nodes[connection[1]]);
            nodes[connection[1]]->parents.push_back(nodes[connection[0]]);
        }

        return CountReversesDFS(nodes[0]);
    }

    static int32_t CountReversesDFS(TreeNode* root) {
        root->state = TreeNodeState::Gray;

        int32_t reverses = 0;

        for (TreeNode* node : root->children) {
            if (node->state == TreeNodeState::White) {
                reverses += 1 + CountReversesDFS(node);
            }
        }

        for (TreeNode* node : root->parents) {
            if (node->state == TreeNodeState::White) {
                reverses += CountReversesDFS(node);
            }
        }

        return reverses;
    }
};
