//
// Created by Mark Volkov on 11/28/17.
//

#ifndef BOOKSTORE_COMMANDMANAGER_H
#define BOOKSTORE_COMMANDMANAGER_H

#include "Command.h"
#include "../dstrctures/map/Map.h"
#include "../books/BookManager.h"

class CommandManager {

private:
    Map<std::string, Command*>* commands;
    BookManager* bookManager;
public:
    CommandManager();
    ~CommandManager();
    Command* getCommand(std::string identifer);
    bool addCommand(Command* command);
    void executeCommand(std::string identifier, std::vector<std::string> args);
    void loadCommands();
    void loadInventory();
};


#endif //BOOKSTORE_COMMANDMANAGER_H
