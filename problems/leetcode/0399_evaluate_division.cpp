#include <iostream>
#include <optional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Node {
    std::string divisor;
    double ratio;

    Node(std::string divisor, double ratio) : divisor(divisor), ratio(ratio) {}
};

class Solution {
public:
    std::optional<double> DFS(const std::string& from,
                              const std::string& to) const {
        std::unordered_set<std::string> visited;

        return DFS(from, to, visited, 1.0);
    }

    std::optional<double> DFS(const std::string& from, const std::string& to,
                              std::unordered_set<std::string>& visited,
                              double ratio) const {
        if (from == to) {
            return ratio;
        }

        visited.insert(from);

        for (const auto& node : graph_.at(from)) {
            if (visited.contains(node.divisor)) {
                continue;
            }

            if (auto answer =
                    DFS(node.divisor, to, visited, ratio * node.ratio)) {
                return answer;
            };
        }

        return std::nullopt;
    }

    double Query(const std::vector<std::string>& query) const {
        const std::string& from = query[0];
        const std::string& to = query[1];

        if (!graph_.contains(from) || !graph_.contains(to)) {
            return -1.0;
        }

        if (from == to) {
            return 1.0;
        }

        std::optional<double> ratio = DFS(from, to);

        return ratio.value_or(-1.0);
    }

    std::vector<double> calcEquation(
        const std::vector<std::vector<std::string>>& equations,
        const std::vector<double>& values,
        const std::vector<std::vector<std::string>>& queries) {
        graph_.reserve(values.size() * 2);

        for (size_t i = 0; i < equations.size(); ++i) {
            const auto& from = equations[i][0];
            const auto& to = equations[i][1];

            graph_[from].emplace_back(to, values[i]);
            graph_[to].emplace_back(from, 1 / values[i]);
        }

        std::vector<double> answers;
        for (const auto& query : queries) {
            answers.push_back(Query(query));
        }

        return answers;
    }

private:
    std::unordered_map<std::string, std::vector<Node>> graph_;
};
