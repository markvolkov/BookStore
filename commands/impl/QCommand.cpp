//
// Created by brien pacholec on 12/12/17.
//

#include "QCommand.h"

QCommand::QCommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string QCommand::toString() {
    std::string qString = "Q - Command: Quit";
    return qString;
}

void QCommand::execute(std::vector<std::string> args) {
    this->bookManager->quit();
    std::cout<<"Inventory has been saved."<<std::endl;
    std::cout<<"Program is shutting down..."<<std::endl;

}

std::string QCommand::getName() {
    return identifier;
}

int QCommand::argumentCount() {
    return 0;
}