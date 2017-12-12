//
// Created by Mark Volkov on 11/28/17.
//

#ifndef BOOKSTORE_COMMANDMANAGER_H
#define BOOKSTORE_COMMANDMANAGER_H

#include "Command.h"
#include "../dstrctures/map/Map.h"
//#include "../dstrctures/map/Item.h"
//#include "../dstrctures/list/array/ArrayList.h"

class CommandManager {

private:
    static Map<std::string, Command*>* commands;
public:
    CommandManager();
    ~CommandManager();
    Command* getCommand(std::string identifer);
    bool addCommand(Command* command);
    void executeCommand(std::string identifier, std::vector<std::string> args);
    static ArrayList<Item<std::string, Command*>*>* getCommands();
    void loadCommands();
};


#endif //BOOKSTORE_COMMANDMANAGER_H
