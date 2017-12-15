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



CommandManager::CommandManager() {
    this->commands = new ArrayMap<std::string, Command*>();
    this->bookManager = new BookManager();
}

CommandManager::~CommandManager() {
    for (int i = 0; i < this->commands->itemSet()->itemCount(); i++) {
        delete this->commands->itemSet()->getValueAt(i);
    }
    delete this->commands;
}

Command* CommandManager::getCommand(std::string identifer) {
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

void CommandManager::executeCommand(std::string identifier, std::vector<std::string> args) {
    Command* command = commands->get(identifier);
    if (command != nullptr) {
        command->execute(args);
    }
}

void CommandManager::loadCommands() {

    Command* aCommand = new ACommand("a", this->bookManager);
    addCommand(aCommand);
    Command* dCommand = new DCommand("d", this->bookManager);
    addCommand(dCommand);
    Command* hCommand = new HCommand("h", this->bookManager);
    addCommand(hCommand);
    Command* iCommand = new ICommand("i", this->bookManager);
    addCommand(iCommand);
    Command* lCommand = new LCommand("l", this->bookManager);
    addCommand(lCommand);
    Command* mCommand = new MCommand("m", this->bookManager);
    addCommand(mCommand);
    Command* oCommand = new OCommand("o", this->bookManager);
    addCommand(oCommand);
    Command* qCommand = new QCommand("q", this->bookManager);
    addCommand(qCommand);
    Command* rCommand = new RCommand("r", this->bookManager);
    addCommand(rCommand);
    Command* sCommand = new SCommand("s", this->bookManager);
    addCommand(sCommand);



}
