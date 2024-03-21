#include <iostream>


class jopa {
public:
    int data;
    jopa(int d) {
        data = d;
    };
};


int main() {
    jopa* j = new jopa(2);

    std::cout << j->data << " " << (*j).data << '\n';
};
