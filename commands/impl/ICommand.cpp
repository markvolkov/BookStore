//
// Created by brien pacholec on 12/5/17.
//

#include "ICommand.h"
//Display all information for a specified title.
ICommand::ICommand(std::string identifier) {
    this->identifier = identifier;
}

std::string ICommand::toString() {
    std::string iString = "I - Command: Inquire Information";
    return iString;
}

void ICommand::execute(std::vector<std::string> args){
    std::string title = args[0];
//    bookManager.getBook(title).getinformation();
}

std::string ICommand::getName() {
    return nullptr;
}
