//
// Created by brien pacholec on 12/5/17.
//

#include "SCommand.h"

SCommand::SCommand() {
    identifier = "not instantiated correctly";
}
SCommand::SCommand(std::string identifier) {
    this->identifier = identifier;
}

int SCommand::argumentCount() {
    return 1;
}

std::string SCommand::toString() {
    std::string sString = "S - Command: Sell Book";
    return sString;}

void SCommand::execute(std::vector<std::string> args) {
    std::cout<<toString()<<std::endl;
}

std::string SCommand::getName() {
    return this->identifier;
}
