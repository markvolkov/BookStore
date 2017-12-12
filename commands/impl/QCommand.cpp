//
// Created by brien pacholec on 12/12/17.
//

#include "QCommand.h"

QCommand::QCommand() {

}

QCommand::QCommand(std::string identifier) {

}

std::string QCommand::toString() {
    std::string qString = "Q - Command: Quit";
    return qString;
}

void QCommand::execute(std::string *args) {

}

std::string QCommand::getName() {
    return std::string();
}
