//
// Created by brien pacholec on 12/5/17.
//

#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
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
//    BookManager::delivery(args[0]);



    std::cout<<"D - COMMAND EXECUTED"<<std::endl;
}

int DCommand::argumentCount() {
    return 1;
}

std::string DCommand::getName() {
    return this->identifier;
}

