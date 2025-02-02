#include <stack>
#include <vector>
#include <cstdint>
#include <iostream>

struct Price {
    int32_t value;
    int32_t span;
};

class StockSpanner {
public:
    StockSpanner() {
        tops_.push({.value=INT32_MAX, .span=0});
    }

    int32_t next(int32_t price) {
        int32_t new_span = 0;
        while (price >= tops_.top().value) {
            new_span += tops_.top().span;
            tops_.pop();
        }

        if (price <= tops_.top().value) {
            tops_.push({.value=price, .span=new_span});
        }

        return ++tops_.top().span;
    }

private:
    std::stack<Price> tops_;
};
