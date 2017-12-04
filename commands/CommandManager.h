//
// Created by Mark Volkov on 11/28/17.
//
using namespace std;

#ifndef BOOKSTORE_COMMANDMANAGER_H
#define BOOKSTORE_COMMANDMANAGER_H

#include "../map/ArrayMap.h"
#include "Command.h"

class CommandManager {

private:
    Map<string, Command*>* commands;
public:
    CommandManager();
    ~CommandManager();
    Command* getCommand(string identifer);
    bool addCommand(Command* command);
    void executeCommand(string identifier);
    void loadCommands();
};


#endif //BOOKSTORE_COMMANDMANAGER_H
