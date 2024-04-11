#include <bitset>
#include <iostream>

/*
Bitwise AND (&)
Bitwise OR (|)
Bitwise XOR (^)
Bitwise NOT (!)


&& and & are different: https://stackoverflow.com/questions/34492501/difference-between-and-or-and
ptr && (*ptr==7) If ptr is zero, the result is false without any risk of seg faulting by dereferencing zero.
*/


bool bitwise_xor(bool a, bool b) {
    if (a == true ^ b == true)
        return false;
    else if (a == true ^ b == false)
        return true;
    else if (a == false ^ b == true)
        return true;
    else
        return false;
};


bool get_bit(int num, int i) {
    return (num & (1 << i)) != 0;
};


int set_bit(int num, int i) {
    return num | (1 << i);
};


int clear_bit(int num, int i) {
    return num & (~(1 << i));
}


void the_fastest_way_to_swap_two_numbers(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
};


int main() {
    int32_t a;
    _Float32 b;


    std::bitset<8> x = -8;
    std::cout << "Bit representation: " << x << '\n';


    std::cout << "\nBitwise shift right (>>) operator: " << (10 >> 1) << '\n';     // 10 / 2 ^ 1; moves bits to right by discarding 1st
    std::cout << "Bitwise shift left (<<) operator: " << (3 << 10) << '\n';     // 3 * 2 ^ 10;  moves bits to left by adding 0


    std::cout << "Bitwise AND (&) operator: " << (13 & 25) << '\n';
/*
     00001101
&    00011001
     _________
     00001001  = 9
*/

   
    std::cout << "Bitwise OR (|) operator: " << (13 | 25) << '\n';
/*
    00001101
|   00011001
    _________
    00011101  = 29
*/


    std::cout << "Bitwise complement (~) operator: " << (~25) << '\n';
/*
~   00011001
    _________
    11100110  = -26
*/

    std::cout << "\nGet bit: " << get_bit(4, 2) << '\n';
    std::cout << "Set bit: " << set_bit(4, 3) << '\n';
    std::cout << "Clear bit: " << clear_bit(4, 2) << '\n';

    int p = 44;
    int q = -33;
    the_fastest_way_to_swap_two_numbers(p, q);
    std::cout << "\nAfter swap: " << p << ", " << q << '\n';


    return 0;
};
