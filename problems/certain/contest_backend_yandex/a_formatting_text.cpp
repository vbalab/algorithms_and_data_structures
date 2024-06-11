#include <string>
#include <iostream>


int find_3len(std::string& s) {
    int len = 0;


    int current_len;
    for (int i = 0; i < s.size(); i++) {
        current_len = 0;

        while (s[i] != ' ' && s[i] != ',' && i < s.size()) {
            current_len++;
            i++;
        };

        if (len < current_len)
            len = current_len;
    };


    return len * 3;
};


void solve(std::string& s) {
    int len = find_3len(s);


    int i = 0;
    std::string element;
    std::string line = "";
    while (i < s.size()) {
        element = "";

        while (s[i] != ' ' && s[i] != ',' && i < s.size())
            element += s[i++];


        if (s[i] == ' ')
            i++;

        if (s[i] == ',')
            element += s[i++];


        if (line.size() + element.size() > len) {
            if (line.back() == ' ')
                line.pop_back();

            std::cout << line << '\n';

            line = "";
        };

        if (element.size() > 0)
            line += element + ' ';
    };

    if (line.size() > 1) {
        if (line.back() == ' ')
            line.pop_back();

        std::cout << line << '\n';
    };


    return;
};


int main() {
    std::string s;
    std::getline(std::cin, s);

    solve(s);

    return 0;
};
