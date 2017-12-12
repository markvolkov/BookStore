//
// Created by Mark Volkov on 11/28/17.
//

#include <iostream>
#include "CommandManager.h"
#include "./impl/ACommand.h"
#include "./impl/DCommand.h"
#include "./impl/HCommand.h"
#include "./impl/ICommand.h"
#include "./impl/LCommand.h"
#include "./impl/MCommand.h"
#include "./impl/OCommand.h"
#include "./impl/QCommand.h"
#include "./impl/RCommand.h"
#include "./impl/SCommand.h"
#include "../dstrctures/map/ArrayMap.h"

CommandManager::CommandManager() {
    this->commands = new ArrayMap<std::string, Command*>();
}

//TODO: Check Item Class
CommandManager::~CommandManager() {
    for (int i = 0; i < this->commands->itemSet()->itemCount(); i++) {
        delete this->commands->itemSet()->getValueAt(i);
    }
    delete this->commands;
}

Command* CommandManager::getCommand(std::string identifer) {
    return commands->get(identifer);
}

bool CommandManager::addCommand(Command* command) {
    commands->put(command->getName(), command);
    return true;
}

void CommandManager::executeCommand(std::string identifier, std::vector<std::string> args) {
    Command* command = commands->get(identifier);
    if (command != nullptr) {
        command->execute(args);
    }
}

ArrayList<Item<std::string, Command*>*>* CommandManager::getCommands() {
    return commands->itemSet();
}

void CommandManager::loadCommands() {
    //Help Command ('h', 'H')
    addCommand(new ACommand("a"));
    addCommand(new DCommand("d"));
    addCommand(new HCommand("h"));
    addCommand(new ICommand("i"));
    addCommand(new LCommand("l"));
    addCommand(new MCommand("m"));
    addCommand(new OCommand("o"));
    addCommand(new QCommand("q"));
    addCommand(new RCommand("r"));
    addCommand(new SCommand("s"));

}
