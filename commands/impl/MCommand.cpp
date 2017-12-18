//
// Created by brien pacholec on 12/5/17.
//

#include "MCommand.h"

MCommand::MCommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string MCommand::toString() {
    std::string mString = "M - Command: Modify Want Value (Title)";
    std::cout<<"IMPORTANT! Make sure there is a space between the command and entry."<<std::endl;
    return mString;}

void MCommand::execute(std::vector<std::string> args) {
    if(this->bookManager->getBook(args[0])== nullptr){
        std::cout<<"Error: This book does not exist. Add it using the A - Command."<<std::endl;
    }
    else {
        std::cout<<"Current want value: "<<this->bookManager->getBook(args[0])->getWishCount()<<"."<<std::endl;
        std::cout<<"Current stock value: "<<this->bookManager->getBook(args[0])->getStockCount()<<"."<<std::endl;
        std::cout<<"Enter how many more copies of "<< args[0]<< " do you want?"<< std::endl;
        std::string wantStr;
        int want;
        getline(std::cin, wantStr);
        try {
             want = std::stoi(wantStr);
        } catch(std::invalid_argument){
            std::cout<<"ERROR: Please enter an integer for the want value!"<<std::endl;
            std::cout<<"Bringing you back to main menu!"<<std::endl;
            return;
        }
        this->bookManager->modifyWant(args[0], want);
    }
}

std::string MCommand::getName() {
    return this->identifier;
}

int MCommand::argumentCount() {
    return 1;
}
