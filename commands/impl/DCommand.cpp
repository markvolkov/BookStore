//
// Created by brien pacholec on 12/5/17.
//

#include "DCommand.h"
//Take information from a file listing the delivery shipment of books.
//The file will contain the title and the count of each book included in the shipment.



DCommand::DCommand(std::string identifier) {
    this->identifier = identifier;
}

std::string DCommand::toString() {
    std::string dString = "D - Command: Delivery Of Books";
    return dString;
}

void DCommand::execute(std::vector<std::string> args) {
    std::cout<<"D - COMMAND EXECUTED"<<std::endl;
}

int DCommand::argumentCount() {
    return 0;
}

std::string DCommand::getName() {
    return this->identifier;
}

