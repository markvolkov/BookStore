//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "commands/CommandManager.h"

std::vector<std::string> explode(const std::string &str, const char &ch) {
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

void prompt(CommandManager *commandManager) {
    std::cout << "\nPlease type 'h' for a list of available commands, or 'q' to exit\n" << std::endl;
    std::string line;
    getline(std::cin, line);
    std::vector<std::string> args = explode(line, ' ');
    int size = args.size();
    std::string command;
    while (args.size() == size) {
        command = args[0];
        Command* toExecute = commandManager->getCommand(command);
        if (command == "q" || command == "quit") {

            toExecute->execute(args);
            delete commandManager;
            commandManager = nullptr;
            delete toExecute;
            toExecute= nullptr;
            break;
        }
        else if (toExecute != nullptr) {
            if (args.size()-1 != toExecute->argumentCount()) {
                std::cout << "Invalid arguments..." << std::endl;
                std::cout << toExecute->toString() << std::endl;
                args.erase(args.begin());
                prompt(commandManager);
            } else {
                args.erase(args.begin());
                toExecute->execute(args);
                prompt(commandManager);
            }
        } else {
            std::cout << "That command doesn't exist!" << std::endl;
            args.erase(args.begin());
            prompt(commandManager);
        }
    }
}

int main() {
    std::cout << "Welcome to your BookStore management system....";

    CommandManager *commandManager = new CommandManager();
    commandManager->loadCommands();
    commandManager->loadInventory();
    prompt(commandManager);
    return 0;

}

