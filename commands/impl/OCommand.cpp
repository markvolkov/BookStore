//
// Created by brien pacholec on 12/5/17.
//

#include "OCommand.h"
//Create a bulk purchase order for additional books based on a comparison of the have and want values in the inventory.

OCommand::OCommand(std::string identifier, BookManager* bookManager) {
    this->identifier=identifier;
    this->bookManager = bookManager;
}

std::string OCommand::toString() {
    std::string oString = "O - Command: Order Books";
    std::cout<<"IMPORTANT! Make sure there is a space between the command and entry."<<std::endl;
    return oString;
}

void OCommand::execute(std::vector<std::string> args) {
    this->bookManager->placeOrder(args[0]);

}

std::string OCommand::getName() {
    return identifier;
}
int OCommand::argumentCount() {
    return 1;
}
