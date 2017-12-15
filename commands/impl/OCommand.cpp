//
// Created by brien pacholec on 12/5/17.
//

#include "OCommand.h"
//Create a bulk purchase order for additional books based on a comparison of the have and want values in the inventory.

OCommand::OCommand() {

}

OCommand::OCommand(std::string identifier) {
    this->identifier=identifier;
}

std::string OCommand::toString() {
    std::string oString = "O - Command: Order Books";
    return oString;
}

void OCommand::execute(std::vector<std::string> args) {
    BookManager::placeOrder(args[0]);

}

std::string OCommand::getName() {
    return identifier;
}
int OCommand::argumentCount() {
    return 1;
}
