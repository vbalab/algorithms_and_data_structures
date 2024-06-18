#include <vector>
#include <iostream>


// class Solution {
// public:
//     int maxDistToClosest(std::vector<int>& seats) {
//         int max = 0;
//         std::vector<int> from_right (seats.size());
//         int counter;
//         int curr;


//         counter = 0;
//         for (int i = seats.size() - 1; i >= 0; i--) {
//             if (seats[i])
//                 counter = -1;

//             from_right[i] = ++counter;
//         }


//         counter = 0;
//         for (int i = 0; i < seats.size(); i++) {
//             if (seats[i])
//                 counter = -1;

//             curr = std::min(++counter, from_right[i]);

//             max = std::max(curr, max);
//         }

//         curr = 0;
//         for (int i = 0; i < seats.size() && !seats[i]; i++)
//             curr++;

//         max = std::max(curr, max);


//         curr = 0;
//         for (int i = seats.size() - 1; i >= 0 && !seats[i]; i--)
//             curr++;

//         max = std::max(curr, max);


//         return max;
//     }
// };


class Solution {
public:
    int maxDistToClosest(std::vector<int>& seats) {
        int max = 0;
        int last_person = 0;
        int counter;


        for (int i = 0; i < seats.size(); i++) {
            if (seats[i]) {
                max = std::max(max, (i - last_person) / 2);
                last_person = i;
            }
        }
        max = std::max(max, static_cast<int>(seats.size() - 1 - last_person));


        counter = 0;
        for (int i = 0; i < seats.size() && !seats[i]; i++)
            counter++;
        max = std::max(max, counter);


        return max;
    }
};


int main() {
    return 0;
}
