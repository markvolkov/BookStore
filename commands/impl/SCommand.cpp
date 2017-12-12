//
// Created by brien pacholec on 12/5/17.
//

#include "SCommand.h"

SCommand::SCommand() {

}

SCommand::SCommand(std::string identifier) {

}

std::string SCommand::toString() {
    std::string sString = "S - Command: Sell Book";
    return sString;}

void SCommand::execute(std::string *args) {

}

std::string SCommand::getName() {
    return std::string();
}
