//
// Created by brien pacholec on 12/5/17.
//

#include "ACommand.h"
#include "../../books/BookManager.h"
//Add a book to the inventory. Prompt for initial want value and have value.
//If the title already exists, inform the user and print the information for that title.

ACommand::ACommand(std::string identifier, BookManager* bookManager) {
    this->identifier = identifier;
    this->bookManager = bookManager;
}

std::string ACommand::toString() {
    std::string aString = "A - Command: Add Book (Title, Want, Have)";
    std::cout<<"IMPORTANT! Make sure there are spaces in between the entries"<<std::endl;
    return aString;
}

void ACommand::execute(std::vector<std::string> args) {
    std::string title =args [0];
    std::string wantStr =args [1];
    std::string needStr =args [2];
    int want = std::stoi(wantStr);
    int stock = std::stoi(needStr);
    std::cout << "Title: " << title << "Want: " << wantStr << "Need: " << needStr << endl;
    this->bookManager->addBook(title,want,stock);
    std::cout << "A-COMMAND EXECUTED" << std::endl;
    std::cout<<args[0]<<" added to the inventory with "<< args[1]<<" amount of copies in stock";

}

int ACommand::argumentCount() {
    return 3;
}

std::string ACommand::getName() {
    return this->identifier;
}
