//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "commands/CommandManager.h"

using namespace std;

//TODO: Implement BookManager
int main() {
    CommandManager commandManager;
    commandManager.loadCommands();

    cout << "Welcome to your BookStore management system...." << endl;
    cout << "Please type 'h' for a list of available commands" << endl;
    bool running = true;
    while(running) {
        string line;
        getline(cin, line);
        stringstream arguments(line);
        while(arguments) {
            string part;

        }

    }


}

vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
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