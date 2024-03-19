#include <queue>
#include <iostream>
#include <stdexcept>


// queue - linear data structure; we can access both ends -> 2 pointers
// FIFO - enqueue (insertion) only from tail=rear, dequeue (removals) only from head=front

// used for processing in specific order - handling requests

// types: circular, priority, double-ended


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


bool isFull(QueueArray* queue) {
    return queue->size == queue->capacity;
};


bool isEmpty(QueueArray* queue) {
    return queue->size == 0;
};


void enqueue(QueueArray* queue, int data) {
    if (isFull(queue))
        throw std::overflow_error("Queue overflow");
    else {
        queue->tail = (queue->tail + 1) % queue->capacity;
        queue->array[queue->tail] = data;

        queue->size += 1;
    };
};


int dequeue(QueueArray* queue) {
    if (isEmpty(queue))
        throw std::underflow_error("Queue underflow");
    else {
        int data = queue->array[queue->head];
        queue->head = (queue->head + 1) % queue->capacity;

        queue->size -= 1;

        return data;
    };
};


int head(QueueArray* queue) {
    if (isEmpty(queue))
        throw std::range_error("Queue is empty.");
    else
        return queue->array[queue->head];
};


int tail(QueueArray* queue) {
    if (isEmpty(queue))
        throw std::range_error("Queue is empty.");
    else
        return queue->array[queue->tail];
};


// LinkedList (dynamic size, extra memory for pointers) ----- ----- ----- ----- -----

int main() {
    QueueArray* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    std::cout << queue->array[queue->tail] << " ";      // or tail(queue)
    std::cout << queue->array[queue->head] << " ";      // or head(queue)
    dequeue(queue);
    std::cout << head(queue) << "\n";


    return 0;
};