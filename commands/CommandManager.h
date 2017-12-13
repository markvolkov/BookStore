//
// Created by Mark Volkov on 11/28/17.
//
using namespace std;

#ifndef BOOKSTORE_COMMANDMANAGER_H
#define BOOKSTORE_COMMANDMANAGER_H

#include "Command.h"
#include "../dstrctures/map/Map.h"

class CommandManager {

private:
    Map<string, Command*>* commands;
public:
    CommandManager();
    ~CommandManager();
    Command* getCommand(string identifer);
    bool addCommand(Command* command);
    void executeCommand(string identifier, vector<string> args);
    void loadCommands();
};


#endif //BOOKSTORE_COMMANDMANAGER_H
