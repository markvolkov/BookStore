//
// Created by brien pacholec on 12/5/17.
//

#include "SCommand.h"

SCommand::SCommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

int SCommand::argumentCount() {
    return 1;
}

std::string SCommand::toString() {
    std::string sString = "S - Command: Sell Book";
    std::cout<<"IMPORTANT! Make sure there is a space between the command and entry."<<std::endl;
    return sString;
}


void SCommand::execute(std::vector<std::string> args) {
    this->bookManager->sellBook(args[0]);

}

std::string SCommand::getName() {
    return this->identifier;
}
