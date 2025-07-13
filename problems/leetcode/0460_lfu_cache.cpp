#include <boost/heap/pairing_heap.hpp>
#include <iostream>
#include <optional>
#include <unordered_map>

template <typename Key, typename Value>
class LfuCache {
    struct Node {
        Key key;
        Value value;
        size_t freq;

        template <typename Val>
            requires std::is_constructible_v<Value, Val&&>
        Node(Key key, Val&& value)
            : key(key), value(std::forward<Val&&>(value)), freq(0) {}
    };

    struct Comparator {
        bool operator()(const Node& lhs, const Node& rhs) const noexcept {
            return lhs.freq > rhs.freq;
        }
    };

    using Heap =
        boost::heap::pairing_heap<Node, boost::heap::compare<Comparator>,
                                  boost::heap::mutable_<true> >;
    using Handle = typename Heap::handle_type;

public:
    LfuCache(size_t capacity) : capacity_(capacity), map_(capacity) {}

    template <typename Val>
        requires std::is_constructible_v<Value, Val&&>
    void Insert(Key key, Val&& value) {
        auto it = map_.find(key);

        if (it != map_.end()) {
            Handle handle = it->second;
            Node& node = *handle;

            node.value = std::forward<Val&&>(value);
            ++node.freq;

            heap_.increase(handle);

            return;
        }

        if (map_.size() == capacity_) {
            map_.erase(heap_.top().key);
            heap_.pop();
        }

        map_[key] = heap_.emplace(key, std::forward<Val&&>(value));
    }

    std::optional<Value> Get(Key key) {
        auto it = map_.find(key);

        if (it == map_.end()) {
            return std::nullopt;
        }

        Handle handle = it->second;
        Node& node = *handle;

        ++node.freq;
        heap_.increase(handle);

        return node.value;
    }

private:
    Heap heap_;
    std::unordered_map<Key, Handle> map_;
    size_t capacity_;
};

class LFUCache {
public:
    LFUCache(int capacity) : cache_(capacity) {}

    int get(int key) {
        if (auto val = cache_.Get(key)) {
            return val.value();
        };

        return -1;
    }

    void put(int key, int value) { cache_.Insert(key, value); }

private:
    LfuCache<int, int> cache_;
};

int main() {
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(2, 4);
    cache.put(3, 3);

    std::cout << cache.get(1);
    std::cout << cache.get(2);
    std::cout << cache.get(3);

    return 0;
}
