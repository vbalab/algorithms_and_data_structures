#include <string>
#include <iostream>
#include <deque>


class Solution {
public:
    std::string simplifyPath(std::string& path) {        // absolute path
        std::string answer;
        std::string command;
        std::deque<std::string> commands;

        int i = 1;
        int size = path.size();
        while (i < size) {
            command.clear();

            while (i < size && path[i] != '/')
                command.push_back(path[i++]);


            if (!command.empty()) {
                if (command == ".." && !commands.empty())
                    commands.pop_back();
                else if (command != ".." && command != ".")
                    commands.push_back(command);
            };


            i++;
        };

        while (!commands.empty()) {
            answer.push_back('/');

            for (char letter: commands.front())
                answer.push_back(letter);

            commands.pop_front();
        }
        
        if (answer.empty())
            return "/";
        else
            return answer;
    };
};


int main() {
    return 0;   
};
