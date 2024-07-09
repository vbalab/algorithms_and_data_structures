#include <stack>
#include <iostream>


class MyQueue {
public:
    std::stack<int> to_pop;
    std::stack<int> to_push;

    MyQueue() {}


    void push(int x) {
        this->to_push.push(x);
    }


    int pop() {
        int val = this->peek();
        this->to_pop.pop();

        return val;
    }


    int peek() {
        if (this->to_pop.empty()) {
            while (!this->to_push.empty()) {
                this->to_pop.push(this->to_push.top());
                this->to_push.pop();
            }
        }

        return this->to_pop.top();
    }


    bool empty() {
        return this->to_pop.empty() && this->to_push.empty();
    }
};


int main() {
    return 0;
}
