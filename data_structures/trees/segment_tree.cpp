#include <vector>
#include <iostream>
#define MAX 1000    // https://stackoverflow.com/questions/6442328/what-is-the-difference-between-define-and-const


/*
segment tree - nodes store result of some operation (like sum) on segment of leafs, leafs are array elements.

               pure array | segment tree
*operation*         O(n) -> O(logn)
update              O(1) -> O(logn)

2n-1 nodes total -> O(n) space.
*/


class SumSegmentTree {
private:
    int left_child(int i) {
        return (i << 1) + 1;
    };


    int right_child(int i) {
        return (i << 1) + 2;
    };


public:
    std::vector<int> array;
    std::vector<int> tree;

    SumSegmentTree(std::vector<int> array) {
        this->array = array;

        this->tree.resize(array.size() << 1);


        this->build(this->array, 0, 0, this->array.size() - 1);
    };


    void build(std::vector<int>& array, int node, int L, int R) {
        if (L == R) {
            this->tree.at(node) = this->array[L];

            return;
        };

        int left_child = this->left_child(node);
        int right_child = this->right_child(node);

        int M = (L + R) >> 1;

        build(array, left_child, L, M);
        build(array, right_child, M + 1, R);


        this->tree[node] = this->tree[left_child] + this->tree[right_child];    // SUM

        return;
    };
};


int main() {
    SumSegmentTree st({ 1, 2, 3, 4 });


    for (int v: st.tree)
        std::cout << v << ' ';
    std::cout << '\n';


    return 0;
};