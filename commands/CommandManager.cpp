//
// Created by Mark Volkov on 11/28/17.
//

#include <iostream>
#include "CommandManager.h"
#include "./impl/HCommand.h"
#include "./impl/ACommand.h"
#include "./impl/ICommand.h"
#include "./impl/MCommand.h"
#include "./impl/SCommand.h"
#include "../dstrctures/map/ArrayMap.h"

using namespace std;

CommandManager::CommandManager() {
    this->commands = new ArrayMap<string, Command*>();
}

//TODO: Check Item Class
CommandManager::~CommandManager() {
    for (int i = 0; i < this->commands->itemSet()->itemCount(); i++) {
        delete this->commands->itemSet()->getValueAt(i);
    }
    delete this->commands;
}

Command* CommandManager::getCommand(string identifer) {
    try {
        Command* command = commands->get(identifer);
        return command;
    } catch (std::out_of_range e) {
        return nullptr;
    }
}

bool CommandManager::addCommand(Command* command) {
    commands->put(command->getName(), command);
    return true;
}

void CommandManager::executeCommand(string identifier, vector<string> args) {
    Command* command = commands->get(identifier);
    if (command != nullptr) {
        command->execute(args);
    }
}

void CommandManager::loadCommands() {
    //Help Command ('h', 'H')
    Command* hCommand = new HCommand("h");
    addCommand(hCommand);

    Command* aCommand = new ACommand("a");
    addCommand(aCommand);

    Command* iCommand = new ICommand("i");
    addCommand(iCommand);

    Command* mCommand = new MCommand("m");
    addCommand(mCommand);

    Command* sCommand = new SCommand("s");
    addCommand(sCommand);



}
