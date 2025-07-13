#include <iostream>
#include <list>
#include <optional>
#include <stdexcept>
#include <unordered_map>

template <typename Key, typename Value>
class LruCache {
    struct Node {
        Key key;
        Value value;
    };

public:
    LruCache(size_t capacity) : capacity_(capacity) {}

    template <typename Val>
        requires std::is_constructible_v<Value, Val&&>
    void Insert(Key key, Val&& value) {
        if (map_.contains(key)) {
            Update(key, std::forward<Val&&>(value));
            return;
        }

        if (map_.size() == capacity_) {
            map_.erase(list_.back().key);
            list_.pop_back();
        }

        Node node{key, std::forward<Val&&>(value)};
        list_.push_front(node);
        map_[key] = list_.begin();
    }

    std::optional<Value> Get(Key key) {
        if (!map_.contains(key)) {
            return std::nullopt;
        }
        Update(key);

        return list_.front().value;
    }

private:
    void Update(Key& key) {
        auto it = map_[key];
        list_.push_front(std::move(*it));
        map_[key] = list_.begin();
        list_.erase(it);
    }

    template <typename Val>
        requires std::is_constructible_v<Value, Val&&>
    void Update(Key& key, Val&& value) {
        auto it = map_[key];
        list_.erase(it);

        list_.push_front(Node(key, std::forward<Val&&>(value)));
        map_[key] = list_.begin();
    }

private:
    std::list<Node> list_;
    std::unordered_map<Key, typename std::list<Node>::iterator> map_;
    size_t capacity_;
};

class LRUCache {
public:
    LRUCache(int capacity) : cache_(capacity) {}

    int get(int key) {
        if (auto val = cache_.Get(key)) {
            return val.value();
        };

        return -1;
    }

    void put(int key, int value) { cache_.Insert(key, value); }

private:
    LruCache<int, int> cache_;
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);

    std::cout << cache.get(1) << '\n'
              << cache.get(2) << '\n'
              << cache.get(3) << '\n';

    return 0;
}