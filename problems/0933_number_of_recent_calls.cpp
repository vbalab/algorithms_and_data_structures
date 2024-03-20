#include <queue>
#include <iostream>


static const int _ = [](){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    return 0;
}();


class RecentCounter {
public:
    std::queue<int> queue;

    RecentCounter() {
        while (!queue.empty())
            queue.pop();
    };

    int ping(int t) {
        queue.push(t);

        int border = queue.back() - 3000;

        while (!queue.empty() & (queue.front() < border))
            queue.pop();

        return queue.size();
    };
};


int main() {
    RecentCounter recentCounter;

    std::cout << recentCounter.ping(1) << '\n';
    std::cout << recentCounter.ping(100) << '\n';
    std::cout << recentCounter.ping(3001) << '\n';
    std::cout << recentCounter.ping(3002) << '\n';

    return 0;
};