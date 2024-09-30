#include <iostream>


class Some {
public:
    int data;


    Some(int d) {
        data = d;
    };
};


int main() {
    int x { 5 };                                        // normal variable

    int& ref { x };                                     // a reference to an integer (bound to x)

    // int& uninitialzied_ref;                          // reference variable requires an initializer

    ref = 6;                                            // will change x

    int y = { 10 };
    int& ref2 { x };
    ref = ref2;                                         // will change value of x, won't take reference to y


    // A "pointer" - variable which value happens to be an address in integer representation.

    float z = 4;
    float* pz = &z;                                     // float* - pointer to a float; it is not float itself, pointer is always int
    float y = *pz;                                      // (without type) * - dereference, to get value from memory address

    std::cout << "address of b is " << &pz << '\n';      // & - address-of, to get the memory address itself; will return the memory address of the first byte used by the object.


    // 2 main ways of dynamically (i.e. while program already running) allocate memory for pointer
    // difference: new initializes after allocation, malloc() just allocates memory
    Some* ptr;

    ptr = new Some(2);                              // prt = new cast_type;
    std::cout << ptr->data << " is the same as " << (*ptr).data << '\n';    // 2 is the same as 2

    ptr = (Some*) malloc(sizeof(Some(2)));          // ptr = (cast_type*) malloc( num_bytes );
    std::cout << ptr->data << " is the same as " << (*ptr).data << '\n';    // 0 is the same as 0 <- since no initilization


    // IF: ptr = nullptr    , then memory leak, do NOT do this 

    delete ptr;                                     // we can 'delete' only dynamically allocated variables

    // "generic pointer": void* is just a nightmare


    const int* pointer_to_constant;
    int* const constant_pointer = &x;                    // const variable requires an initializer

    return 0;
};
