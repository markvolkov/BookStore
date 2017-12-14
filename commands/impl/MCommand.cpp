//
// Created by brien pacholec on 12/5/17.
//

#include "MCommand.h"
#include "../../books/BookManager.h"

MCommand::MCommand() {};

MCommand::MCommand(std::string identifier) {
    this->identifier = identifier;
}

std::string MCommand::toString() {
    std::string mString = "M - Command: Modify Want Value";

    return mString;}

void MCommand::execute(std::vector<std::string> args) {
//    std::cout<<"Current Want Value: "<< BookManager::getBook(arg[0])->getWishCount();
//    std::cout<<"Current Have Value: "<< BookManager::getBook(arg[0])->getStockCount();


    std::cout<<"Enter how many more copies of "<<args[0]<< " do you need/want?"<<std::endl;
    std::string line;
    getline(std::cin, line);
    std::stoi(line);
//    BookManager::getBook(args[0])->addToWishCount(line);

}

std::string MCommand::getName() {
    return this->identifier;
}

int MCommand::argumentCount() {
    return 1;
}
