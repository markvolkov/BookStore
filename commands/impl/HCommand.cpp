//
// Created by Mark Volkov on 11/28/17.
//
#include "HCommand.h"

HCommand::HCommand() {
    this->identifier = "error";
}
HCommand::HCommand(std::string identifier){
    this->identifier = identifier;
}

std::string HCommand::toString() {
    std::string hString = "H - Command: Help";
    return hString;
}

void HCommand::execute(std::string args[]) {
    std::cout << toString() << std::endl;
}


std::string HCommand::getName() {
    return this->identifier;
}

