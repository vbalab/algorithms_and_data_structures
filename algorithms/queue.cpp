#include <queue>
#include <iostream>
#include <stdexcept>


// queue - linear data structure; we can access both ends -> 2 pointers
// FIFO - enqueue (insertion) only from tail=rear=back, dequeue (removals) only from head=front

// used for processing in specific order - handling requests

// types: circular, priority, double-ended = deque


// Array (fixed size) ----- ----- ----- ----- -----
class QueueArray {
public:
    unsigned int capacity;      // for array
    
    int tail, head;

    int size;                   // number of existing elements

    int* array;
};


QueueArray* createQueue(unsigned int capacity) {
    QueueArray* queue = new QueueArray();

    queue->capacity = capacity;
    queue->size = 0;

    queue->head = 0;
    queue->tail = capacity - 1;

    queue->array = new int[capacity];

    return queue;
};


bool isFull(QueueArray* queue) {            // O(1)
    return queue->size == queue->capacity;
};


bool isEmpty(QueueArray* queue) {           // O(1)
    return queue->size == 0;
};


void enqueue(QueueArray* queue, int data) { // O(1)
    if (isFull(queue))
        throw std::overflow_error("Queue overflow");
    else {
        queue->tail = (queue->tail + 1) % queue->capacity;
        queue->array[queue->tail] = data;

        queue->size += 1;
    };
};


int dequeue(QueueArray* queue) {            // O(1)
    if (isEmpty(queue))
        throw std::underflow_error("Queue underflow");
    else {
        int data = queue->array[queue->head];
        queue->head = (queue->head + 1) % queue->capacity;

        queue->size -= 1;

        return data;
    };
};


int head(QueueArray* queue) {               // O(1)
    if (isEmpty(queue))
        throw std::range_error("Queue is empty.");
    else
        return queue->array[queue->head];
};


int tail(QueueArray* queue) {               // O(1)
    if (isEmpty(queue))
        throw std::range_error("Queue is empty.");
    else
        return queue->array[queue->tail];
};


// LinkedList (dynamic size, extra memory for pointers) ----- ----- ----- ----- -----
class QueueNode {
public:
    int data;
    QueueNode* link;

    QueueNode(int d) {
        data = d;
        link = nullptr;
    };
};


class QueueLinkedList {
public:
    QueueNode* tail;
    QueueNode* head;

    QueueLinkedList() {
        tail = nullptr;
        head = nullptr;
    };

    void enqueue(int x);
    void dequeue();
};


void QueueLinkedList::enqueue(int x) {
    QueueNode* temp = new QueueNode(x);

    if (tail == nullptr) {  // queue is empty
        head = temp;
        tail = temp;
        return;
    };

    tail->link = temp;
    tail = temp;
};


void QueueLinkedList::dequeue() {
    if (head == nullptr)
        throw std::range_error("Queue is empty.");

    QueueNode* temp = head;
    head = head->link;

    if (head==nullptr)
        tail = nullptr;

    delete(temp);
};


int main() {
    // Array:
    QueueArray* queueA = createQueue(1000);

    enqueue(queueA, 10);
    enqueue(queueA, 20);
    enqueue(queueA, 30);

    std::cout << queueA->array[queueA->tail] << " ";      // or tail(queue)
    std::cout << queueA->array[queueA->head] << " ";      // or head(queue)
    dequeue(queueA);
    std::cout << head(queueA) << "\n";


    // LinkedList:
    QueueLinkedList queueLL;
    queueLL.enqueue(10);
    queueLL.enqueue(20);
    queueLL.enqueue(30);

    std::cout << queueLL.tail->data << " ";
    std::cout << queueLL.head->data << " ";
    queueLL.dequeue();
    std::cout << queueLL.head->data << "\n";


    // STD:
    std::queue<int> queueSTD;
    queueSTD.push(10);
    queueSTD.push(20);
    queueSTD.push(30);

    std::cout << queueSTD.back() << " ";
    std::cout << queueSTD.front() << " ";
    queueSTD.pop();
    std::cout << queueSTD.front() << "\n";


    return 0;
};