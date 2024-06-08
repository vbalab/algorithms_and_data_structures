#include <vector>
#include <iostream>
#include <unordered_set>


int solve(std::vector<char>& moves) {
    int diff = 0;
    int direction = 1;
    std::vector<int> diffs;
    std::vector<int> directions;
    std::unordered_set<int> positions;


    for (int i = 0; i < moves.size(); i++) {
        if (moves[i] != 'F') {
            diffs.push_back(diff);
            diff = 0;

            directions.push_back(direction);
            if (moves[i] == 'L')
                direction = -1;
            else
                direction = 1;
        }
        else
            diff += direction;
    };
    diffs.push_back(diff);
    directions.push_back(direction);


    for (int i = diffs.size() - 1; i >= 0; i--) {                                       // change of one of F to L,R
        if (diffs[i] != 0) {
            int change = directions[i] * (std::abs(diffs[i]) - 1);

            for (int j = change; j <= -change; j += 2)
                positions.insert(j - diffs[i]);

            for (int j = -change; j <= change; j += 2)
                positions.insert(j - diffs[i]);
        };
    };


    for (int i = diffs.size() - 1; i > 0; i--) {
        positions.insert(directions[i - 1] * (std::abs(diffs[i]) + 1) - diffs[i]);      // change from L,R to F

        positions.insert(-2 * diffs[i]);                                                // L->R or R->L
    };


    return positions.size();
};


int main() {
    int N;
    std::cin >> N;

    std::vector<char> moves (N);
    for (int i = 0; i < N; i++)
        std::cin >> moves[i];

    std::cout << solve(moves) << '\n';

    return 0;
};
