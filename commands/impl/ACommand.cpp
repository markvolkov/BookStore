//
// Created by brien pacholec on 12/5/17.
//

#include "ACommand.h"
//Add a book to the inventory. Prompt for initial want value and have value.
//If the title already exists, inform the user and print the information for that title.


ACommand::ACommand(std::string identifier) {
    this->identifier = identifier;
}

std::string ACommand::toString() {
    std::string aString = "A - Command: Add Book";
    return aString;
}

void ACommand::execute(std::vector<std::string> args) {
//    std::string title =args [0];
//    std::string wantStr =args [1];
//    std::string needStr =args [2];
//    int* want = new int(wantStr);
//    int* need = new int(needStr);
//    BookManager.createBook.create
    std::cout << "A-COMMAND EXECUTED" << std::endl;




}

int ACommand::argumentCount() {
    return 0;
}

std::string ACommand::getName() {
    return this->identifier;
}
