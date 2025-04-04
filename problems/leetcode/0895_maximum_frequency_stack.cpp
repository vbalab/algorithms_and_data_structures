#include <cstddef>
#include <cstdint>
#include <stack>
#include <unordered_map>

class FreqStack {
public:
  FreqStack() : freq_(0) {}

  void push(int32_t val) {
    mapstack_[++count_[val]].push(val);

    freq_ = std::max(freq_, count_[val]);
  }

  int32_t pop() {
    if (mapstack_[freq_].empty()) {
      --freq_;
    }

    int32_t elem = mapstack_[freq_].top();

    --count_[elem];
    mapstack_[freq_].pop();

    return elem;
  }

private:
  size_t freq_;
  std::unordered_map<int32_t, size_t> count_;
  std::unordered_map<size_t, std::stack<int32_t>> mapstack_;
};
