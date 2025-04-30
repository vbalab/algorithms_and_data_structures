#include <string>

struct Party {
    size_t alive = 0;
    size_t ban_right = 0;
};

class Solution {
public:
    std::string predictPartyVictory(std::string& senate) {  // NOLINT
        Party radiant;
        Party dire;

        for (char senator : senate) {
            if (senator == 'R') {
                ++radiant.alive;
            } else {
                ++dire.alive;
            }
        }

        while (radiant.alive > 0 && dire.alive > 0) {
            for (char& senator : senate) {
                if (senator == 'R') {
                    if (dire.ban_right > 0) {
                        --dire.ban_right;
                        --radiant.alive;

                        senator = 'B';
                    } else {
                        ++radiant.ban_right;
                    }
                } else if (senator == 'D') {
                    if (radiant.ban_right > 0) {
                        --radiant.ban_right;
                        --dire.alive;

                        senator = 'B';
                    } else {
                        ++dire.ban_right;
                    }
                }
            }
        }

        if (radiant.alive > 0) {
            return "Radiant";
        }
        return "Dire";
    }
};
