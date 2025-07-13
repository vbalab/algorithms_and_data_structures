#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include <stack>
#include <variant>
#include <vector>

class NestedInteger {
public:
    using List = const std::vector<NestedInteger>;

public:
    bool isInteger() const { return std::holds_alternative<int32_t>(value_); }

    int32_t getInteger() const { return std::get<int32_t>(value_); }

    List& getList() const { return std::get<List>(value_); }

    NestedInteger(int32_t x) : value_(x) {}
    NestedInteger(List x) : value_(x) {}

private:
    std::variant<int32_t, List> value_;
};

class FlattenIterator {
    struct LevelInteger {
        const NestedInteger* nested;
        size_t index;

        LevelInteger(const NestedInteger* nested) : nested(nested), index(0) {}

        bool operator==(const LevelInteger& other) {
            return index == other.index && nested == other.nested;
        }
    };

public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = std::optional<int32_t>;
    using difference_type = std::ptrdiff_t;

public:
    explicit FlattenIterator(const NestedInteger& obj) {
        LevelInteger level(&obj);
        stack_.push(level);

        FindNextElement();
    }

    FlattenIterator& operator++() {
        stack_.pop();

        FindNextElement();

        return *this;
    }

    value_type operator*() const {
        if (stack_.empty()) {
            return std::nullopt;
        }

        return stack_.top().nested->getInteger();
    }

    bool operator==(const FlattenIterator& other) {
        return stack_ == other.stack_;
    }

    bool operator!=(const FlattenIterator& other) {
        return stack_ != other.stack_;
    }

private:
    void FindNextElement() {
        if (stack_.empty() || stack_.top().nested->isInteger()) {
            return;
        }

        LevelInteger& top = stack_.top();
        const std::vector<NestedInteger>& list = top.nested->getList();

        if (top.index < list.size()) {
            LevelInteger new_top(&list[top.index++]);
            stack_.push(new_top);
        } else {
            stack_.pop();
        }

        return FindNextElement();
    }

private:
    std::stack<LevelInteger> stack_;
};

int main() {
    NestedInteger nested = NestedInteger({1, NestedInteger({2, 3}), 4});

    FlattenIterator it(nested);

    for (size_t i = 0; i < 3; ++i) {
        std::cout << **it << '\n';
        ++it;
    }
    std::cout << **it << '\n';

    return 0;
}
