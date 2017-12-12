//
// Created by Mark Volkov on 11/28/17.
//
#include "HCommand.h"
#include "../CommandManager.h"

HCommand::HCommand(std::string identifier){
    this->identifier = identifier;
}

std::string HCommand::toString() {
    std::string hString = "H - Command: Help";
    return hString;
}

void HCommand::execute(std::vector<std::string> args) {
    ArrayList<Item<std::string, Command*>*>* commands = CommandManager::getCommands();
    for (int i = 0; i < commands->itemCount(); i++) {
        Item<std::string, Command*>* entry = commands->getValueAt(i);
        entry->getValue()->toString();
    }
}


std::string HCommand::getName() {
    return this->identifier;
}

