#include <iostream>


class Some {
public:
    int data;


    Some(int d) {
        data = d;
    };
};


int main() {
    Some* ptr;

    // 2 main ways of dynamically (i.e. while program already running) allocate memory for pointer
    // difference: new initializes after allocation, malloc() just allocates memory

    ptr = new Some(2);                              // prt = new cast_type;
    std::cout << ptr->data << " is the same as " << (*ptr).data << '\n';    // 2 is the same as 2

    ptr = (Some*) malloc(sizeof(Some(2)));          // ptr = (cast_type*) malloc( num_bytes );
    std::cout << ptr->data << " is the same as " << (*ptr).data << '\n';    // 0 is the same as 0 <- since no initilization


    // IF: ptr = nullptr    , then memory leak, do NOT do this 

    delete ptr;                                     // we can 'delete' only dynamically allocated variables

    // "generic pointer": void* is just a nightmare


    return 0;
};
