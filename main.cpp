//
// Created by Mark Volkov on 11/14/17.
//

#include <iostream>
#include <vector>
#include <sstream>
#include "commands/CommandManager.h"

using namespace std;

string* split(const string& s, char delimiter)
{
    int size = s.length();
    string* args = new string[s.length()];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == delimiter) continue;
        args[count] = s[i];
        count++;
    }
    return args;
}

int main() {
    CommandManager commandManager;
    commandManager.loadCommands();
    //TODO: Implement BookManager

    bool running = true;
    while(running) {
        string line;
        getline(cin, line);

        if (line == "quit" || line == "q") {
            running = false;
        } else {
            string* args = split(line, ' ');
            if (args->length() == 1) {
//                commandManager.executeCommand(args[0], nullptr);
                cout << args[0] << endl;
            } else {
//                commandManager.executeCommand(args[0], split(args[1], ' '));
                cout << args[0] + " " << split(args[1], ' ') << endl;
            }
        }

    }


}
