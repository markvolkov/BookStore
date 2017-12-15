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

using namespace std;

CommandManager::CommandManager() {
    this->commands = new ArrayMap<string, Command*>();
}

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


    Command* aCommand = new ACommand("a");
    addCommand(aCommand);
    Command* dCommand = new DCommand("d");
    addCommand(dCommand);
    Command* hCommand = new HCommand("h");
    addCommand(hCommand);
    Command* iCommand = new ICommand("i");
    addCommand(iCommand);
    Command* lCommand = new LCommand("l");
    addCommand(lCommand);
    Command* mCommand = new MCommand("m");
    addCommand(mCommand);
    Command* oCommand = new OCommand("o");
    addCommand(oCommand);
    Command* qCommand = new QCommand("q");
    addCommand(qCommand);
    Command* rCommand = new RCommand("r");
    addCommand(rCommand);
    Command* sCommand = new SCommand("s");
    addCommand(sCommand);



}
