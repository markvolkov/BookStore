//
// Created by brien pacholec on 12/5/17.
//

#include "ICommand.h"
//Display all information for a specified title.
ICommand::ICommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string ICommand::toString() {
    std::string iString = "I - Command: Inquire Information";
    std::cout<<"IMPORTANT! Make sure you type in the Title"<<std::endl;
    return iString;
}

void ICommand::execute(std::vector<std::string> args){
    std::string title = args[0];
    std::cout << "Inquire: " << title << std::endl;
//    BookManager::getInfo(args[0]);

}

std::string ICommand::getName() {
    return identifier;
}

int ICommand::argumentCount() {
    return 1;
}
