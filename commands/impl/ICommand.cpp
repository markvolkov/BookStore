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
    std::string iString = "I - Command: (Inquire Information On Title)";
    std::cout<<"IMPORTANT! Make sure there is a space between the command and entry."<<std::endl;
    return iString;
}

void ICommand::execute(std::vector<std::string> args){
    std::string title = args[0];
    this->bookManager
            ->getInfo
                    (args[0],
                     bookManager->
                             getBook(args[0]));

}

std::string ICommand::getName() {
    return identifier;
}

int ICommand::argumentCount() {
    return 1;
}
