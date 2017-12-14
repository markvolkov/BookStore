//
// Created by brien pacholec on 12/12/17.
//

#include "RCommand.h"

RCommand::RCommand() {

}

RCommand::RCommand(std::string identifier) {
    this->identifier = identifier;
}

std::string RCommand::toString() {
    std::string rString = "R - Command: Return";
    return rString;
}


void RCommand::execute(std::vector<std::string> args) {

}

std::string RCommand::getName() {
    return this->identifier;
}

int RCommand::argumentCount() {
    return 1;
}