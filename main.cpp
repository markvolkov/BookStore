//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "commands/CommandManager.h"

//TODO: Implement BookManager
int main() {
    CommandManager commandManager;
    commandManager.loadCommands();

    std::cout << "Welcome to your BookStore management system...." << std::endl;
    std::cout << "Please type 'h' for a list of available commands" << std::endl;
    bool running = true;
    while(running) {
        std::string line;
        getline(std::cin, line);
        std::stringstream arguments(line);
        while(arguments) {
            std::string part;

        }

    }


}

std::vector<std::string> explode(const std::string& str, const char& ch) {
    std::string next;
    std::vector<std::string> result;

    // For each character in the string
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}