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
    std::cout<<"Enter how many more copies of "<<args[0]<< " do you need/want?"<<std::endl;
    std::string want;
    getline(std::cin, want);
    int wantInt = std::stoi(want);
    this->bookManager->modifyWant(args[0],wantInt);

}

std::string MCommand::getName() {
    return this->identifier;
}

int MCommand::argumentCount() {
    return 1;
}
