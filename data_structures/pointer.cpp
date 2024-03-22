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
    ptr = new Some(2);                            // prt = new cast_type;
    ptr = (Some*) malloc(sizeof(Some(2)));        // ptr = (cast_type*) malloc( num_bytes );
    // difference: new initializes after allocation, malloc() just allocates memory


    std::cout << ptr->data << " is the same as " << (*ptr).data << '\n';

    return 0;
};
