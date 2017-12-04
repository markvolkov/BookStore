//
// Created by Mark Volkov on 11/28/17.
//

#include <iostream>
#include "CommandManager.h"
#include "./impl/HCommand.h"
using namespace std;

CommandManager::CommandManager() {
    this->commands = new ArrayMap<string, Command*>();
}

//TODO: Check Item Class
CommandManager::~CommandManager() {
    for (int i = 0; i < this->commands->itemSet()->itemCount(); i++) {
        delete this->commands->itemSet()->getValueAt(i);
    }
//    delete this->commands;
}

Command* CommandManager::getCommand(string identifer) {
    return commands->get(identifer);
}

bool CommandManager::addCommand(Command* command) {
    if (commands->get(command->identifier) != nullptr) {
        cout << "That command already exists." << endl;
        return false;
    }
    commands->put(command->identifier, command);
    return true;
}

void CommandManager::executeCommand(string identifier) {
    Command* command = commands->get(identifier);
    if (command != nullptr) {
        command->execute();
    }
}

void CommandManager::loadCommands() {
    //Help Command ('h', 'H')
    Command* helpCommand = new HCommand("h");
    addCommand(helpCommand);


}
