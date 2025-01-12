#include <vector>
#include <iostream>
#include <algorithm>

class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : cur_(1) {
    }
    
    int32_t popSmallest() {
        if (heap_.empty()) {
            return cur_++;
        }

        std::pop_heap(heap_.begin(), heap_.end(), std::greater<int32_t>());
        int32_t min = heap_.back();
        heap_.pop_back();
        return min;
    }
    
    void addBack(int32_t num) {
        if (num >= cur_) {
            return;
        }

        auto it = std::find(heap_.begin(), heap_.end(), num);

        if (it == heap_.end()) {
            heap_.push_back(num);
            std::push_heap(heap_.begin(), heap_.end(), std::greater<int32_t>());
        }
    }

private:
    int32_t cur_;
    std::vector<int32_t> heap_;
};
