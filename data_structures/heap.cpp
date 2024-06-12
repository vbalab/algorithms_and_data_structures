#include <queue>
#include <vector>
#include <random>
#include <iostream>
#include <stdexcept>
#include <algorithm>


/*
MIN/MAX heap - hierarchical d.s. based on a tree;

heap property: the value of each node is <= (>=) to the value of its children;
structural property: heap should be a Complete *Binary* Tree.

implementation: array, pointers.
*/


// array-based binary heap of min;
class HeapMin {
    int* harr;
    int capacity;
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    };


    int left_child(int i) {
        return 2 * i + 1;
    };


    int right_child(int i) {
        return 2 * i + 2;
    };

    void siftDown(int i);

    void siftUp(int i);

    void heapify(int i);

public:
    HeapMin (int capacity);

    int top();

    void pop();

    void insert(int val);

    void changeValue(int i, int val);

    void remove(int i);

    void show();
};


HeapMin::HeapMin(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->harr = new int[capacity];
};


int HeapMin::top() {
    if (this->size > 0)
        return this->harr[0];
    else
        throw std::range_error("Heap is empty");
};


void HeapMin::pop() {
    if (this->size == 0)
        throw std::underflow_error("Heap underflow");
    else if (this->size == 1)
        this->size--;
    else {
        this->harr[0] = this->harr[--this->size];
        this->heapify(0);
    }

    return;
};


void HeapMin::siftDown(int i) {
    int l = this->left_child(i);
    int r = this->right_child(i);

    if (l < this->size && this->harr[l] < this->harr[i]) {
        std::swap(this->harr[l], this->harr[i]);

        this->siftDown(l);
    }
    else if (r < this->size && this->harr[r] < this->harr[i]) {
        std::swap(this->harr[r], this->harr[i]);

        this->siftDown(r);
    }

    return;
};


void HeapMin::siftUp(int i) {
    if (i == 0)
        return;

    int parent = this->parent(i);

    if (harr[parent] > harr[i]) {
        std::swap(harr[i], harr[parent]);

        this->siftUp(parent);
    };

    return;
};


void HeapMin::heapify(int i) {
    for (int i = this->size - 1; i >= 0; i--)
        siftDown(i);

    return;
};


void HeapMin::insert(int val) {
    if (this->size < this->capacity) {
        this->harr[size] = val;

        this->siftUp(this->size++);
    }
    else
        throw std::overflow_error("Heap overflow");

    return;
};


void HeapMin::changeValue(int i, int val) {
    if (i >= 0 && i < this->size) {
        this->harr[i] = val;

        this->heapify(i);
    }
    else
        throw std::range_error("Out of bounds");

    return;
};


void HeapMin::remove(int i) {
    this->changeValue(i, INT32_MIN);
    this->siftUp(i);
    this->pop();
};


void HeapMin::show() {
    for (int i = 0; i < this->size; i++)
        std::cout << this->harr[i] << ' ';

    std::cout << '\n';

    return;
};


void print_vector(std::vector<int> v) {
    for (int num: v)
        std::cout << num << ' ';
    std::cout << '\n';
};


int main() {
    // Array:
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1000(0, 1000);

    HeapMin heap = HeapMin(100);

    for (int i = 0; i < 10; i++)
        heap.insert(dist1000(rng));


    std::cout << heap.top() << '\n';
    heap.show();
    
    heap.pop();
    heap.show();

    heap.changeValue(2, 10);
    heap.show();

    heap.remove(3);
    heap.show();


    // STD:
    /*
    make_heap(): Converts given range to a heap.
    push_heap(): Arrange the heap after insertion at the end.
    pop_heap(): Moves the max element at the end for deletion.
    sort_heap(): Sort the elements of the max_heap to ascending order.
    is_heap(): Checks if the given range is max_heap.
    is_heap_until(): Returns the largest sub-range that is max_heap.
    */
    std::vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(dist1000(rng));

    print_vector(v);


    std::make_heap(v.begin(), v.end());
    print_vector(v);

    std::pop_heap(v.begin(), v.end());
    v.pop_back();
    print_vector(v);

    v.push_back(1100);
    std::push_heap(v.begin(), v.end());
    print_vector(v);

    std::sort_heap(v.begin(), v.end());
    print_vector(v);


    return 0;
};
