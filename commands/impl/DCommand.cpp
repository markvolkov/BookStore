//
// Created by brien pacholec on 12/5/17.
//

#include "DCommand.h"




//Take information from a file listing the delivery shipment of books.
//The file will contain the title and the count of each book included in the shipment.



DCommand::DCommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string DCommand::toString() {
    std::string dString = "D - Command: (Delivery Of Books)";
    std::cout<<"IMPORTANT! Make sure there is a space between the command and entry."<<std::endl;
    return dString;
}

void DCommand::execute(std::vector<std::string> args) {
    bookManager->delivery(args[0]);

}

int DCommand::argumentCount() {
    return 1;
}

std::string DCommand::getName() {
    return this->identifier;
}

