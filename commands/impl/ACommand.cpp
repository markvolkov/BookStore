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
    std::string aString = "A - Command: Add Book (Title)";
    std::cout<<"IMPORTANT! Make sure there are spaces between the command and entries."<<std::endl;
    return aString;
}

void ACommand::execute(std::vector<std::string> args) {
    std::string title  =args [0];
    int stock;
    int want;
    std::cout << "Please enter how many copies of "<<title<<" you WANT: " << std::endl;
    std::string wantStr;
    getline(std::cin, wantStr);
    std::cout << "Please enter how many copies of "<<title<<" you HAVE: " << std::endl;
    std::string stockStr;
    getline(std::cin, stockStr);

    try {
        stock = std::stoi(stockStr);
        want = std::stoi(wantStr);
    } catch(std::invalid_argument){
        std::cout<<"ERROR: Please enter integers for the have/want value!"<<std::endl;
        std::cout<<"Bringing you back to main menu!"<<std::endl;
        return;
    }
    this->bookManager->addBook(title,want,stock);


}

int ACommand::argumentCount() {
    return 1;
}

std::string ACommand::getName() {
    return this->identifier;
}
